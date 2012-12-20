#include <stdio.h>
#include <stdlib.h>


int calcCheckSum(FILE* file) {
    int c;
    unsigned int checksum=0;
    unsigned int word=0;
    
    fseek(file,sizeof(checksum),SEEK_SET);
    c = fread(&checksum, 1,sizeof(checksum), file);

    while(fread(&word, 1,sizeof(word), file))
    {
      checksum ^= word;
      word=0;
    }
    
    return checksum;
}
