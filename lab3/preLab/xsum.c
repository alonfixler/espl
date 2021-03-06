#include "xsum.h"

int main(int argc, char** argv) {
    int c,flag=0;
    char* filename;
    FILE * file;
    unsigned int checksum;
    unsigned int word;
    
    
    while((c = getopt (argc, argv, "-hx:"))!=-1)
    {
      switch(c)
      {
	    case 1:
	      filename = optarg;
	    case 'h':
	      printf("OPTIONS\n\t-h  print a summary of options and exit\n\t-x  print the checksum as a hexadecimal rather than decimal number.\n");
	      exit(0);
	      break;
	    case 'x':
	      filename = optarg;
	      flag=1;
	      break;
	    default:
	      fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",argv[0]);
	      exit(EXIT_FAILURE);
      }
    }
    file = fopen(filename,"r");
    
    c = fread(&checksum, 1,sizeof(checksum), file);
    
    while(fread(&word, 1,sizeof(word), file))
    {
      checksum ^= word;
      word=0;
    }
    if(flag==1)
    {
      printf("0x%x\n",checksum);
    }
    else
      printf("%d\n",checksum);
    
    fclose(file);
    return 0;
}
