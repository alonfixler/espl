#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xsum.h"

void createFileName(char* newFile,char* filename,int counter)
{
   char buff[5];
   sprintf(buff,"%d",counter);
   newFile[0] = 0;
   strcat(newFile,"Files/");
   strcat(newFile,filename);
   if (counter<10)
      strcat(newFile,"0");
   strcat(newFile,buff);
}

int main(int argc, char **argv) {
    int c,chunkSize=1024,fileSize,counter=1,read;
    char* filename;
    FILE * file,*fp;
    unsigned int checksum=0,totalSum=0;
    char buff[100];
    int x=0;
    
    
    while((c = getopt (argc, argv, "-hx:b:"))!=-1)
    {
      switch(c)
      {
	    case 1:
	      filename = optarg;
	    case 'h':
	      printf("OPTIONS\n\t-b SIZE     put at most SIZE bytes per output file\n\t-h          print summary of options and exit\n\t-x          print the checksum of FILE on the standard output\n");
	      exit(0);
	      break;
	    case 'x':
	      x=1;
	      filename = optarg;
	      break;
	    case 'b':
	      chunkSize = atoi(optarg);
	      break;
	    default:
	      fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",argv[0]);
	      exit(EXIT_FAILURE);
      }
    }
    
    char word[chunkSize];
    filename = argv[optind];
    file = fopen(filename,"r");
    memset(word,0,chunkSize);
    while(!((read = fread(&word, 1,chunkSize, file))))
    {
      char newFile[strlen(filename)+100];
      createFileName(newFile,filename,counter);
      fp = fopen(newFile,"w");
      checksum = calcCheckSum(fp);
      totalSum ^= checksum;
      sprintf(buff,"%d",checksum);
      //fwrite(buff,sizeof,1,fp);
      fwrite(word,read,1,fp);
      counter++;
      fclose(fp);
      memset(word,0,chunkSize);
    }
    
    if(x==1)
    {
        file = fopen(filename,"r");
	printf("0x%x\n",totalSum);
    }
    
      return 0;
}
