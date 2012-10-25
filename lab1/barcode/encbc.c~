#include <assert.h>
#include <stdio.h>
#include "bclib.h"

int main(int argc, char **argv) {
  
  
  int barcode[BC_WIDTH][BC_NBITS] = {0};
  int i, j, k;

  /* convert */
  for(i = 1,k=0;i!=argc;i++,k++){
    for(j = 0; argv[i][j]!= '\0'; j++,k++){
      bc_char2bits(argv[i][j],barcode[k]);
    }
	if(i<argc-1){
	  bc_char2bits(' ',barcode[k]);
	}
  }
      
      
    //printf("%d\n",counter);
    /* print */
  for(i=0;i<BC_NBITS;i++){
    for(j=0;j<BC_WIDTH;j++){
      if(barcode[j][i]==1)
	printf("#");
      else
	printf(" ");
    }
    printf("\n");
  }
  //printf("\n");

    return 0;
}
