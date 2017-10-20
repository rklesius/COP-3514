//This program finds either the largest or smallest of 10 numbers as command
//line arguments.  This program uses -l to represent the command for find 
//largest and -s for the command for find smallest.  This program also displays
//a message for an invalid option.  
//By Rachel Klesius

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	int i;
	if (argc <= 2){
		printf("Incorrect amount of inputs\n");
		return 0;
		}
	int largest = atoi(argv[2]);  //sets the first value to largest
	int smallest = atoi(argv[2]); //sets the first value to smallest
	if (strcmp(argv[1], "-l") == 0){
		for (i = 2; i < argc; i++)
			if((atoi(argv[i])) > largest)
				largest = atoi(argv[i]);
		printf("The largest number is %d\n", largest);
		return 0;
		}		
	if (strcmp(argv[1], "-s") == 0){
		for (i = 2; i < argc; i++)
			if((atoi(argv[i])) < smallest)
				smallest = atoi(argv[i]);
		printf("The smallest number is %d\n", smallest);
		return 0;
		}
	printf("Invalid input\n");
	return 0;
}

