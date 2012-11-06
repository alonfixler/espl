#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    int c,flag=0;
    FILE * file;
    unsigned int checksum;
    unsigned int word;
    
    
    while((c = getopt (argc, argv, "hx:"))!=-1)
    {
      switch(c)
      {
	    case 'h':
	      printf("OPTIONS\n\t-h  print a summary of options and exit\n\t-x  print the checksum as a hexadecimal rather than decimal number.\n");
	      exit(0);
	      break;
	    case 'x':
	      flag=1;
	      break;
	    default:
	      fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",argv[0]);
	      exit(EXIT_FAILURE);
      }
    }
    file = fopen(argv[argc-1],"r");
    
    c = fread(&checksum, sizeof(checksum), 1, file);
    while(fread(&word, sizeof(word), 1, file))
    {
      checksum ^= word;
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
