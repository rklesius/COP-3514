//This program reads the contents of a file and translates the seven-letter
//words into the corresponding phone number (ABC - 2, DEF - 3 etc).  The phone
//numbers are then written to a file with the same name but with .cvt appended
//to the end of it.  This program runs under the assumption that the file name
//is no more than 100 characters.  
//By Rachel Klesius

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

void translate(char *word, char *phone_number);
int readline(char *str, int n);  //used to read in the file name

int main(void)
{	FILE* pFile;  //points to file read from
	FILE* qFile;  //points to file to be written to
	char filename[MAX_LEN];	//file name string
	char str[MAX_LEN];	//a line of text in pFile
	char number[MAX_LEN];	//a line of text in qFile
	
	printf("Enter the file name: ");
	readline(filename, MAX_LEN);
	pFile = fopen(filename, "r");
	
	
	if (pFile == NULL){ 	//checks if file read from can be opened
		printf("File cannot be opened.\n");
		return 1;
	}	
	
	qFile = fopen(strcat(filename, ".cvt"), "w");

	if (qFile == NULL){	//checks if file to write to can be opened
		printf("File cannot be written to.\n");
		return 1;
	}
	
	printf("Output file name: %s\n", filename);

	while (!feof(pFile)&&!ferror(pFile)){
		if ( fgets(str, MAX_LEN, pFile) != NULL){
			translate(str, number);
			fputs(number, qFile);
			fputs("\n", qFile);
			}
		}
	fclose(pFile);
	fclose(qFile);
	return 0;
}

//translate takes in word, a string containing the seven-letter words to be
//translated, and alters phone_number, the pointer pointing to the string 
//to contain the translated phone number.  
void translate(char *word, char *phone_number)
{	char *p;
	char *q;
	for (p = word, q = phone_number; *p != '\0'; p++, q++){
		if (*p >= 'A' && *p <= 'C')
			*q = '2';
		if (*p >= 'D' && *p <= 'F')
			*q = '3';
		if (*p >= 'G' && *p <= 'I')
			*q = '4';
		if (*p >= 'J' && *p <= 'L')
			*q = '5';
		if (*p >= 'M' && *p <= 'O')
			*q = '6';
		if (*p >= 'P' && *p <= 'S')
			*q = '7';
		if (*p >= 'T' && *p <= 'V')
			*q = '8';
		if (*p >= 'W' && *p <= 'Z')
			*q = '9';
		}
		
	return;
}

//readline function used to read in the user input for the file name.  
//Alters str parameter, n is the maximum length of the string to be read.

int readline(char *str, int n)
{	int ch, i = 0;
	while ((ch = getchar())!= '\n')
	{	if (i < n)
		{	*str++= ch;
			i++;
		}
	}
	*str = '\0';  //terminating null character
	return i;  //number of characters
}

