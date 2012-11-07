#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "xsum.h"

int main(int argc, char **argv) {
    int c,chunkSize,fileSize,counter=1,read;
    char* filename;
    FILE * file,fp;
    unsigned int checksum;
    
    
    while((c = getopt (argc, argv, "-hx:o:"))!=-1)
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
	      filename = optarg;
	      file = fopen(filename,"r");
	      printf("0x%x\n",calcCheckSum(file));
	      break;
	    case 'o':
	      chunkSize = atoi(optarg);
	      char word[chunkSize];
	      filename = argv[optind];
	      file = fopen(filename,"r");
	      memset(word,0,chunkSize);
	      while(!((read = fread(&word, 1,chunkSize, file))))
	      {
		char newFile[strlen(filename)+100];
		createFileName(newFile,filename,counter);
		fp = fopen(newFile,"w");
		char buff[100];
		checksum = calcCheckSum(fp);
		sprintf(buff,"%d",checksum);
		//fwrite(buff,sizeof,1,fp);
		fwrite(word,read,1,fp);
		counter++;
		fclose(fp);
		memset(word,0,chunkSize);
	      }
	      break;
	    default:
	      fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",argv[0]);
	      exit(EXIT_FAILURE);
      }
    }
    return 0;
}
