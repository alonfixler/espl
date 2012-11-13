#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xsum.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char **argv) {
    int c,chunkSize,fileSize,read;
    char *filename,*output,prefix[200],suffix[5],tempPre[200],word;
    FILE * file,*fp;
    unsigned int checksum;
    int flago=0,flagx=0,counter;
    unsigned int totalSum=0;
    
    while((c = getopt (argc, argv, "-hx:o:"))!=-1)
    {
      switch(c)
      {
	    case 1:
	      filename = optarg;
	      break;
	    case 'h':
	      printf("OPTIONS\n\t-h          print summary of options and exit\n\t-o OUTPUT   write the output into OUTPUT instead of PREFIX\n\t-x CHECKSUM verify that the checksum of the produced file is CHECKSUM\n");
	      exit(0);
	      break;
	    case 'x':
	      flagx = 1;
	      filename = argv[argc-1];
	      break;
	    case 'o':
	      flago=1;
	      output = optarg;
	      filename = argv[argc-1];
	      break;
	    default:
	      fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",argv[0]);
	      exit(EXIT_FAILURE);
      }
    }
    
    struct stat st = {0};
    if (stat("Files", &st) == -1) {
	printf("The desired folder doesn't exist\n");
	exit(0);
    }

    if(flago==1)
      fp = fopen(output,"w+");
    else
      fp = fopen(filename,"w+");
    
    strcpy(prefix,"Files/");
    strcat(prefix,filename);
    strcpy(tempPre,prefix);
    strcat(tempPre,".1");
    suffix[0] = '1';
    file = fopen(tempPre,"r");
    
    while(file!=NULL)
    {
      unsigned int checksum=0;
      fseek(file,sizeof(checksum),SEEK_SET);
      checksum = calcCheckSum(file);
      totalSum^=checksum;
      rewind(file);
      fseek(file,sizeof(checksum),SEEK_SET);
      while(((read = fread(&word, 1,1, file))))
      {
	  fwrite(&word,sizeof(word),1,fp);  
      }
      printf("%d\n",read);
      
      counter = atoi(suffix)+1;
      sprintf(suffix,"%d",counter);
      strcpy(tempPre,prefix);
      strcat(tempPre,".");
      strcat(tempPre,suffix);
      file = fopen(tempPre,"r");
    }
    
    if(flagx==1)
    {
      printf("0x%x\n",totalSum);
    }
    
    return 0;
}
