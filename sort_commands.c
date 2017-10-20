//This program sorts the inputs from the command line alphabetically by word
//and then print the sorted array of strings. 
//By Rachel Klesius 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp_str(const void *p, const void *q);

int main(int argc, char *argv[])
{	int i;
	int length = argc - 1;
	qsort(argv++, argc, sizeof(char *), cmp_str);
	for(i = 0; i < length; i++)
		printf("%s ", argv[i]);
	printf("\n");
	return 0;
}

int cmp_str(const void *p, const void *q)
{	return strcmp(*(char **)p, *(char **)q);
}
