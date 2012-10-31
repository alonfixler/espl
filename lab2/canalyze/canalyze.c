#include <stdio.h>
#include <stdlib.h>
#include "fgetname.h"
#include "namelist.h"
#include <string.h>

int compareNames(const void* a,const void* b);

int main(int argc,char** argv)
{
  //int strcmp (char * a, char * b);
  namelist nl = make_namelist();
  char* words[] = {"auto","double","int","long",
		  "break","else","long","switch",
		  "case","enum","register","typedef",
		  "char","extern","return","union",
		  "const","float","short","unsigned",
		  "continue","for","signed","void",
		  "default","goto","sizeof","volatile",
		  "do","if","static","while"
		  };
  
  int i,j,flag;
  char name[NAMELEN];
  FILE * file;
  
  for(i=1;i<argc;i++)
  {
    file = fopen(argv[i],"r");
    while(fgetname(name,NAMELEN,file))
    {
      //printf("%s\n",name);
      flag=0;
      for(j=0;j<32;j++)
      {
	if(!strcmp(name,words[j]))
	  flag=1;
      }
      if(!flag)
	add_name(nl,name);
    }
    fclose(file);
  }
  
  qsort(nl->names,nl->size,sizeof(struct namestat),compareNames);
  for(i=0;i<nl->size;i++)
    printf("%s %d\n",nl->names[i].name,nl->names[i].count);
    
  return 0;
}

int compareNames(const void* a,const void* b)
{
  return strcmp(((struct namestat*)a)->name,((struct namestat*)b)->name);
}
