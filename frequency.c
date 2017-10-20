//frequency.c reads in a line of text and computes the frequency of the words 
//in the text (assuming words are separated by white spaces, comma, period, or
//exclamation point.  Assumes input is no longer than 1000 characters, assumes
//the input contains no more than 1000 words, assumes each word is no more than
//50 characters.  
//By Rachel Klesius

#include <stdio.h>
#include <string.h>
#define A_MAX 1000 //array max (input/number of words)
#define W_MAX 50   //word size max

int read_line(char *str, int n);

int main(void)
{	char words[W_MAX][A_MAX] = {{0}};
	int word_count[A_MAX] = {0};
	int n = 0;		//number of different words
	int i;			//used to read across arrays
	char *p;		//used to read across input
	char input[A_MAX];	//user input
	
	printf("Input:\n");
	read_line(input, A_MAX);
	
	p = strtok(input, " ,.!");
	while (p != NULL){
		//search if word is already in words
		for (i = 0; i < n; i++){
			if (strcmp(p, words[i]) == 0){
				break; //get out of for, saves i
				}
			}
		if (i < n) //checks if iteration is within amount of words
			word_count[i]++;  
		else { 	   //not within word amount, new word
			strcpy(words[n], p);
			word_count[i]++;
			n++;
			}

		p = strtok(NULL, " ,.!");
	}
		
	printf("Output:\n");
	
	for (i = 0; i < n; i++)
		printf("%s\t\t\t%d\n", words[i], word_count[i]); 
	return 0;
				
}

//read line reads in a string that will be stored at the pointer str.  The n 
//parameter is the maximum length.  Returns the actual length of the string.

int read_line(char *str, int n)
{	int ch, i = 0;
	while ((ch = getchar()) != '\n')
	{	if (i < n)
		{	*str++= ch;
			i++;
		}
	}
	*str = '\0';  //terminates string
	return i; //number of characters in string
}
