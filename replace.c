//replace.c asks the user to enter a three digit integer and then replace 
//each digit by the sum of that digit plus 6 modulus 10.   If the integer
//entered is less than 100 or greater than 999, it outputs an error message 
// and aborts.  By Rachel Klesius

#include <stdio.h>
#define UPPER_LIMIT 999
#define LOWER_LIMIT 100

int main(void){
	int number, first, second, third;
	printf("Enter a three-digit number: ");
	scanf(" %d", &number);
	if (number < LOWER_LIMIT || number > UPPER_LIMIT){
		printf("Input is not between 100 and 999");
		return 0;
		}
	first = ((number / 100) + 6) % 10;
	second = (((number % 100) / 10) + 6) % 10;
	third = ((number % 10) + 6) % 10;
	printf("Output: %d%d%d\n", first, second, third);
	return 0;
}
