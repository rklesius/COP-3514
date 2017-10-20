//This program adds, subtracts, and multiplies complex numbers.  This program 
//prompts the user for the choice of operations, reads in the complex numbers,
//performs the operations, and prints the result.  The main program repeatedly
//prints the menu, reads in the user's selection and performs the operation.
//By Rachel Klesius
 
#include <stdio.h>
void read_numbers(double *r1, double *i1, double *r2, double *i2);
void add(double r1, double i1, double r2, double i2, double *r3, double *i3);
void subtract(double r1, double i1, double r2, double i2, double *r3, double *i3);
void multiply(double r1, double i1, double r2, double i2, double *r3, double *i3);
void print_complex(double r3, double i3); 

int main(void)
{
	double r1, r2, r3, i1, i2, i3;
	int option;
	
	printf("Complex Number Arithmetic Program: \n\n");
	for(;;)
	{
		printf("1. Add two complex numbers\n");
		printf("2. Subtract two complex numbers\n");
		printf("3. Multiply two complex numbers\n");
		printf("4. Quit\n\n");

		printf("Choose an option (1 - 4): ");
		scanf("%d", &option);
		switch(option){
			case 1:
				read_numbers(&r1, &i1, &r2, &i2);
				add(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 2:
				read_numbers(&r1, &i1, &r2, &i2);
				subtract(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 3:
				read_numbers(&r1, &i1, &r2, &i2);
				multiply(r1, i1, r2, i2, &r3, &i3);
				print_complex(r3, i3);
				break;
			case 4:
				return 0;
			default:
				printf("Invalid option. Choose an option (1-4):\n");

		}
	}

	return 0;
}

//read_numbers prompts the user to enter the real component and imaginary
//component of the first number and the second number and stores the values
//in the variables pointed by r1, i1, r2, i2, modifying them in the main
//function.  This function takes in the pointers that are to be modified.

void read_numbers(double *r1, double *i1, double *r2, double *i2)
{	printf("Enter the first real number: ");
	scanf("%lf", r1);
	printf("Enter the first imaginary number: ");
	scanf("%lf", i1);
	printf("Enter the second real number: ");
	scanf("%lf", r2);
	printf("Enter the second imaginary number: ");
	scanf("%lf", i2);
}

//add adds two complex numbers and modifies *r3 and *i3 with the added values of the parameters r1, i1, r2, and i2.  
void add(double r1, double i1, double r2, double i2, double *r3, double *i3)
{	*i3 = i1 + i2;
	*r3 = r1 + r2;
	return;
}

//subtract subtracts two complex numbers and modifies *r3 and *i3 with the
//subtracted values of the parameters r1, i1, r2, and i2.  
void subtract(double r1, double i1, double r2, double i2, double *r3, double *i3)
{	*i3 = i1 - i2;
	*r3 = r1 - r2;
	return;
}

//multiply multiplies two complex numbers and modifies *r3 and *i3 with the 
//multiplied values of the parameters r1, i1, r2, and i2.  
void multiply(double r1, double i1, double r2, double i2, double *r3, double *i3)
{	*i3 = (i1 * r2) + (r1 * i2);
	*r3 = (r1 * r2) - (i1 * i2);
	return;
}

//print_complex prints the complex variables
void print_complex(double r3, double i3)
{
	if(i3 >= 0)
		printf("The operation yields %.3f + %.3fi\n\n", r3, i3);
	else
		
		printf("The operation yields %.3f  %.3fi\n\n", r3, i3);
}


