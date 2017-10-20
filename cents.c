//This program will use pointer variables given to functions to find the least
//amount of each type of coin possible for the amount of cents given.  
//Edited by Rachel Klesius

#include <stdio.h>
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1
void coins(int cents, int *quarters, int *dimes, int *nickels, int *pennies);

int main()
{
	//initialize variables and read input
	int cents, pennies, quarters, dimes, nickels;
	pennies = quarters = dimes = nickels =0;
	int *q;
	int *d;
	int *n;
	int *p;
	q = &quarters;
	d = &dimes;
	n = &nickels;
	p = &pennies;
        printf("Enter the number of cents:\n");
	scanf("%d", &cents);

	//check the range of the input amount
	if(cents< 0 || cents > 10000)
	   printf("Invalid amount %d,\nAmount must be between 0 and 10000, inclusive\n", cents);
        else {
		coins( cents, q, d, n, p);
		printf("Quarters: %d\n", *q);
	        printf("Dimes: %d\n", *d);
        	printf("Nickels: %d\n", *n);
	        printf("Pennies: %d\n", *p);
	}
	return 0;
}

//coins takes in the value of the change and a pointer to each type of coin
//and returns nothing.  This program alters the values of coins using the 
//pointers.  

void coins(int cents, int *quarters, int *dimes, int *nickels, int *pennies)
{	*quarters = cents/QUARTER;
	*dimes = cents%QUARTER/DIME;
	*nickels = cents%QUARTER%DIME/NICKEL;
	*pennies = cents%QUARTER%DIME%NICKEL;	
	return;
}	
