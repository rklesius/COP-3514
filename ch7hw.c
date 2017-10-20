//This program contains programming projects 11 and 12 from chapter 7 (Basic types).  
//By Rachel Klesius

#include <stdio.h>
float calculate(float a, char ch, float b);

int main(void)
{
//11: Write a program that takes a first name and last name entered by the user and displays the last name, a comma, and the first initial
//followed by a period.  The user's input may contain extra spaces before the first name, between the first and last names, and after the
//last name.
	char first, last;
	printf("Enter a first and last name: ");
	while ((first = getchar()) == ' '); /* skips blanks */
	while ((last = getchar()) != ' ');  /* looks for next space and then stores it */
	do {
		if (last == ' ')
			continue;
		printf("%c", last);
	} while ((last = getchar()) != '\n');
	printf(", %c\n", first);
	
//12: Write a program that evaluates an expression.  The operands in the expression are floating-point numbers; the operators are +, -, *, and /.
//The expression is evaluated from left to right (no operator takes precedence over any other operator).  
	float i, j, sum = 0;  
	char operand;
	printf("Enter an expression: ");
	scanf("%f%c%f", &i, &operand, &j);
	sum = calculate(i, operand, j);
	do {
		scanf("%c", &operand);
		if(operand == '\n')
			break;
		scanf("%f", &j);
		sum = calculate(sum, operand, j);
	} while (operand != '\n');
	printf("Value of expression: %.2f\n", sum);
	return 0;
}


//calculate is used in question 12 to calculate an answer based off of the two floating values inputed and the character operator.
//Returns the appropriate calculation between the two floats as a float.

float calculate(float a, char ch, float b)
{	float answer;
	switch (ch) {
		case '+': answer = a + b;
			break;
		case '-': answer = a - b;
			break;
		case '*': answer = a * b;
			break;
		case '/': answer = a / b;
			break;
		default: answer = a;  /* assumes the answer is the first float */ 
	}
	return answer;
}
