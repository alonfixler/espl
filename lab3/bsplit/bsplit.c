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
   strcat(newFile,".");
   strcat(newFile,buff);
}

int main(int argc, char **argv) {
    int c,chunkSize=1024,fileSize,counter=1,read;
    char* filename;
    FILE * file,*fp;
    unsigned int checksum=0,totalSum=0;
    char buff[100];
    int flagx=0;
    
    
    while((c = getopt (argc, argv, "hx:b:"))!=-1)
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
	      flagx=1;
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
    
    int line = 48;

    char word[chunkSize];
    filename = argv[optind];
    file = fopen(filename,"r");
    memset(word,0,chunkSize);
   
    while(((read = fread(&word, 1,chunkSize, file))))
    {
      char newFile[strlen(filename)+100];
      createFileName(newFile,filename,counter);
    
      printf("%s\n",newFile);
      fp = fopen(newFile,"w");
      line=63;
      printf("%d\n",line);
      checksum = calcCheckSum(fp);
       line=66;
      printf("%d\n",line);
      totalSum ^= checksum;
       line=69;
      printf("%d\n",line);
      sprintf(buff,"%d",checksum);
       line=72;
      printf("%d\n",line);
      //fwrite(buff,sizeof,1,fp);
      fwrite(word,read,1,fp);
       line=76;
      printf("%d\n",line);
      counter++;
       line=79;
      printf("%d\n",line);
      fclose(fp);
       line=82;
      printf("%d\n",line);
      memset(word,0,chunkSize);
    }
    printf("%d\n",read);
    line=70;
    printf("%d\n",line);
    
    if(flagx==1)
    {
        file = fopen(filename,"r");
	printf("0x%x\n",totalSum);
    }
    line=78;
    printf("%d\n",line);
    
      return 0;
}
