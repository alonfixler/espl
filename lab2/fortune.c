#include <stdio.h>


int main(int argc, char **argv) {
	int i,j,counter;
	FILE * file;
	char line[100];
	
	file = fopen(argv[1],"r");
	srand(time(NULL));
	
	/* read for counting */
	for(counter=0;fgets(line,100,file);counter++);
	i = rand()%counter+1;
	rewind(file);
		
	/* decode */	
	for(j=1; j<i;j++) 
	  fgets(line,100,file);
	fgets(line,100,file);

    /* print */
    printf("%d: %s\n",i,line);
	
    fclose(file);

    return 0;
}
