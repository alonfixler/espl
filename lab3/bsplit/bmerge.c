#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xsum.h"


int main(int argc, char **argv) {
    int c,chunkSize,fileSize,read;
    char *filename,prefix[200],suffix[5],tempPre[200];
    FILE * file,fp;
    unsigned int checksum;
    int flago=0,flagx=0,counter;
    
    while((c = getopt (argc, argv, "hx:o:"))!=-1)
    {
      switch(c)
      {
	    case 1:
	      filename = optarg;
	
	    case 'h':
	      printf("OPTIONS\n\t-h          print summary of options and exit\n\t-o OUTPUT   write the output into OUTPUT instead of PREFIX\n\t-x CHECKSUM verify that the checksum of the produced file is CHECKSUM\n");
	      exit(0);
	      break;
	    case 'x':
	      flagx = 1;
	      filename = optarg;
	      break;
	    case 'o':
	      flago = 1;
	      filename = optarg;
	     
	      break;
	    default:
	      fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",argv[0]);
	      exit(EXIT_FAILURE);
      }
    }
    
    strcpy(prefix,filename);
    strcpy(tempPre,prefix);
    strcat(tempPre,".1");
    suffix[0] = "1";
    while(fopen(tempPre,"r"))
    {
      
      
      counter = atoi(suffix)+1;
      sprintf(suffix,"%d",counter);
      strcpy(tempPre,prefix);
      strcat(tempPre,".");
      strcat(tempPre,suffix);
    }
    
    return 0;
}
