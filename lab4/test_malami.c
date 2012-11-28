#include <stdlib.h>
#include <stdio.h>

extern int malami(char * string);

int main(int argc, char **argv) {
	printf("%d\n",malami(argv[1]));

	return 0;
}
