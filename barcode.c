//This program scans a 'barcode' containing 8 bits  inputted by the
//user and detects the edges of light and dark regions.  The output assigns a
//1 to the output bit pattern whenever one bit and its previous bit are different
//and assigns a 0 to the output bit pattern when they are the same.  The first
//bit is automatically 0.  
//By Rachel Klesius

#include <stdio.h>
#define MAX 8
void edge(int n, int a1[], int a2[]);

int main(void)
{	int i, input[MAX], output[MAX] = {0};
	printf("Input:\t");
	for (i = 0; i < MAX; i++)
		scanf("%1d", &input[i]);
	printf("Output:\t");
	edge(MAX - 1, input, output);
	printf("\n");
	return 0;
}

//The function 'edge' performs the edge detection taking in the length of the
//input and output arrays (n), the input array a1, and output array a2.  
void edge(int n, int a1[], int a2[])
{	if(n == 0){
		for (; n < MAX; n++)
			printf("%d", a2[n]);
		return;
		}
	if(a1[n] != a1[n-1])
		a2[n] = 1;
	edge(n - 1, a1, a2);
}
