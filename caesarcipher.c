//This program uses one of the oldest encription techniques by replacing each letter in a message
//with another letter that is a fixed number of positions later in the alphabet, wrapping around
//if a letter exceeds "z".  
//By Rachel Klesius

#include <stdio.h>
#define MAX 80

int main(void)
{	char a[MAX];
	int i, shift;
	printf("Enter the message to be encrypted: ");
	for (i = 0; (a[i] = getchar()) != '\n'; i++);
	printf("Enter the shift amount (1-25): ");
	scanf(" %d", &shift);
	printf("Encrypted message: ");
	for (i = 0; a[i] != '\n'; i++) {
		if ((a[i] >= 'a') && (a[i] <= 'z')) 
			a[i] = ((a[i] - 'a') + shift) % 26 + 'a';
		if ((a[i] >= 'A') && (a[i] <= 'Z'))
			a[i] = ((a[i] - 'A') + shift) % 26 + 'A';
		printf("%c", a[i]);
		}
	printf("\n");
	return 0;
}
