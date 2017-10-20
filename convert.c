//convert.c displays menus for converting length and calculates the result. 
//This program supports conversions from miles to kilometers, kilometers to miles,
//inches to centimeters, and centimeters to inches in a menu format.  

#include <stdio.h>

int main(void){
	int option;
	double input, output;
	printf("1 - Miles to Kilometers\n2 - Kilometers to Miles\n3 - Inches to Centimeters\n4 - Centimeters to Inches\n");
	printf("Please input a numerical selection based on the menu: ");
	scanf(" %d", &option);
	switch(option){
		case 1:printf("Enter the amount of Miles: ");
		       scanf(" %lf", &input);
		       output = input * 1.6093;
		       printf("Converted to Kilometers: %.2f\n", output);
		       break;
		case 2:printf("Enter the amount of Kilometers: ");
		       scanf(" %lf", &input);
		       output = input * 0.6214;
		       printf("Converted to Miles: %.2f\n", output);
		       break;
		case 3:printf("Enter the amount in Inches: ");
		       scanf(" %lf", &input);
		       output = input * 2.54;
		       printf("Converted to Centimeters: %.2f\n", output);
	   	       break;
		case 4:printf("Enter the amount in Centimeters: ");
		       scanf(" %lf", &input);
		       output = input * 0.3937;
		       printf("Converted to Inches: %.2f\n", output);
		       break;
		default: printf("Invalid input, program terminated\n");
		} 
	return 0;
}
