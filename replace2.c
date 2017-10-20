//This program asks a user to enter a positive integer (within the range of the
//integer type) and replaces each digit by the sum of that digit plus 6 modulus
//10.  The program then swaps the first digit with the last digit before it
//displays the output.  
//By Rachel Klesius 

#include <stdio.h>

void replace(int *a, int *b, int n);
void swap(int *p, int *q);

int main(void)
{	int size;
	int *p;
	printf("Enter the number of digits of the number: ");
	scanf("%d", &size);
	int input[size], output[size];
	printf("Enter the number: ");
	for(p = input; p < input + size; p++) 
		scanf("%1d", p);
	replace(input, output, size);
	swap(output, output + size - 1);
	printf("Output: ");
	for(p = output; p < output + size; p++)
		printf("%d", *p);
	printf("\n");
	return(0);
}

//replace uses pointer arithmetic to visit array elements and uses the elements
//in array a to calculate the elements in array b.  n represents the size of the
//arrays.  This functions alters output.  
void replace(int *a, int *b, int n)
{	int *p, *q;
	q = b;
	for(p = a; p < a + n; p++)
		*q++ = (*p + 6) % 10;
	return;
}


//swap swaps two integers at the addresses given.  This function alters output.  
void swap(int *p, int *q)
{	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
	return;
}


