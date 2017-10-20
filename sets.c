//This program reads in two sets of numbers, A and B, and calculates and prints
//their union (values in either A or B)  and intersection (values in both A
//and B).  The values in the sets are restricted to the range 0 - 9.  
//By Rachel Klesius
	
#include <stdio.h>
#define MAX 10

int main(void)
{	int i, j, length_A, length_B, A[MAX] = {0}, B[MAX] = {0}; 
	printf("Enter the number of elements in set A: ");
	scanf(" %d", &length_A);
	printf("Enter the numbers in set A: ");
	for(i = 0; i < length_A; i++){
		scanf(" %d", &j);
		A[j]++;
		}
	printf("Enter the number of elements in set B: ");
	scanf(" %d", &length_B);
	printf("Enter the numbers in set B: ");
	for(i = 0; i < length_B; i++){
		scanf(" %d", &j);
		B[j]++;
		}
	printf("Output\n");
	//Union
	printf("The union of set A and B is: ");
	for(i = 0; i < MAX; i++)
		if((A[i] > 0) || (B[i] > 0))
			printf(" %d", i);
	//Intersection
	printf("\nThe intersection of set A and B is: ");
	for(i = 0; i < MAX; i++)
		if((A[i] > 0) && (B[i] > 0))
			printf(" %d", i);
	printf("\n");
	return 0;
}
