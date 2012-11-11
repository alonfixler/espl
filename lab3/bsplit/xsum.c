#include <stdio.h>
#include <stdlib.h>


int calcCheckSum(FILE* file) {
    int c;
    unsigned int checksum=0;
    unsigned int word=0;
    int line;
    
   FILE * fp;
   fp = fopen("bsplit.c","r");
    c = fread(&checksum, 1,sizeof(checksum), fp);
    //c = fread(&checksum, 1,sizeof(checksum), file);
    line=14;
    printf("%d\n",line);
    while(fread(&word, 1,sizeof(word), file))
    {
       line=18;
      printf("%d\n",line);
      checksum ^= word;
      word=0;
    }
     line=23;
      printf("%d\n",line);
    return checksum;
}
