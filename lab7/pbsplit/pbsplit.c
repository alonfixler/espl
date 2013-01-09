#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xsum.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


void createFileName(char* newFile,char* filename,int counter)
{
   char buff[5];
   sprintf(buff,"%d",counter);
   newFile[0] = 0;
   strcat(newFile,"Files/");
   strcat(newFile,filename);
   strcat(newFile,".");
   strcat(newFile,buff);
}

int main(int argc, char **argv) {
    int c,chunkSize=1024,fileSize,counter=1,read;
    char* filename;
    FILE * file,*fp;
    unsigned int totalSum=0;
    char buff[100];
    int flagx=0,count=0;
    int i,pid,status,offset;
    unsigned int checksum=0;
    
    
    while((c = getopt (argc, argv, "-hx:b:"))!=-1)
    {
      switch(c)
      {
	    case 1:
	      filename = optarg;
	      break;
	    case 'h':
	      printf("OPTIONS\n\t-b SIZE     put at most SIZE bytes per output file\n\t-h          print summary of options and exit\n\t-x          print the checksum of FILE on the standard output\n");
	      exit(0);
	      break;
	    case 'x':
	      flagx=1;
	      filename = argv[argc-1];
	      break;
	    case 'b':
	      if(optarg!=0) 
		chunkSize = atoi(optarg);
	      filename = argv[argc-1];
	      break;
	    default:
	      fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",argv[0]);
	      exit(EXIT_FAILURE);
      }
    }

    file = fopen(filename,"r");
   
    struct stat st = {0};
    if (stat("Files", &st) == -1) {
      mkdir("Files", 0700);
    }
    
    fseek(file,0,SEEK_END);
    int numOfBytes = ftell(file);
    int numOfProc = (numOfBytes+chunkSize-1)/chunkSize;
    
    
    for(i=0;i<numOfProc;i++)
    {
      int pid = fork();
      if (pid== -1) 
      {
	perror("fork");
	exit(EXIT_FAILURE);
      }
      
      else if(pid==0)
      {
	unsigned int word = 0;
	offset = i*(chunkSize-4);
	fseek(file,offset,SEEK_SET);
	read = fread(&word, 1,sizeof(word), file);
	checksum = word;
	char newFile[strlen(filename)+100];
	createFileName(newFile,filename,counter);
	fp = fopen(newFile,"w+");
	count = read*2;
	fwrite(&word,1,read,fp);
	fwrite(&word,1,read,fp);
	while(1)
	{
	  word=0;
	  if(!((count<((chunkSize-4)+sizeof(checksum)))&&(read = fread(&word , 1 , sizeof(word) , file)))) break;
	  checksum ^= word;
	  count += read;
	  fwrite(&word, 1 , read, fp);
	}
	fseek(fp , 0 , SEEK_SET);
	fwrite(&checksum , 1 , sizeof(checksum), fp);
	fclose (fp);
      }
      return 0;
    }
    
   waitpid(pid, &status, 0);
    
   return 0;
}
 
