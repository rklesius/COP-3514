//This program demonstrates some problems and their solutions for Ch6 (Loops)
//By Rachel Klesius

#include <stdio.h>

int main(void)
{	//#11
	int i, sum = 0;
	for (i = 0; i < 10; i++){
		if (i % 2)
			continue;
		sum += i;
	}
	printf("The answer to #11 is: %d\n", sum);
	return 0;
}
