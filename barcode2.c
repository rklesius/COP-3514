//This program scans a 'barcode' containing 8 bits  inputted by the
//user and detects the edges of light and dark regions.  The output assigns a
//1 to the output bit pattern whenever one bit and its previous bit are different
//and assigns a 0 to the output bit pattern when they are the same.  The first
//bit is automatically 0.  
//By Rachel Klesius

#include <stdio.h>
#define MAX 8
void edge(int n, int *a1, int *a2);

int main(void)
{	int input[MAX], output[MAX] = {0};
	int *p;
	printf("Input:\t");
	for (p = input; p < input + MAX; p++)
		scanf("%1d", p);
	printf("Output:\t");
	edge(MAX, input, output);
	printf("\n");
	return 0;
}

//The function 'edge' performs the edge detection taking in the length of the
//input and output arrays (n), the input array a1, and output array a2. edge also
//transforms input and output in main.    
void edge(int n, int *a1, int *a2)
{	int *p, *q;
	p = a1;
	q = a2;
	printf("%d", *q++);
	for(p = a1 + 1; p < a1 + n; p++){
		if(*p != *(p - 1))
			*q = 1;
		printf("%d", *q++);
		}
	return;
}
