//This program extracts the web addresses starting with www. and ending with
//.edu.  This program displays the web address contained in the input entered
//by the user.  If the input does not contain a web address that starts with
//www. and ends with .edu, the program should display a message that indicates
//such a web address cannot be found.
//By Rachel Klesius  

#include <stdio.h>
#define N 1000

void read_line(char *str, int n);
void extract(char *s1, char *s2);

int main(void)
{	char input[N], output[N] = {'\0'};
	char *p;
	printf("Input: ");
	read_line(input, N);  //return value void
	extract(input, output);
	printf("Output: ");
	if(output[0] == '\0'){ //determines if anything was saved to output
		printf("Web address starting with www. and ending with\n.edu not found\n");
		return 0;
		}
	for(p = output; *p != '\0'; p++)  //prints output
		if(*p != '\0')
			printf("%c", *p);
	printf("\n");
	return 0;
	
}

//read_line reads in a character string and stores it in the character array
//pointed to by the parameter char *str.  The other parameter, n, is the length
//of the array being pointed to.  This function returns a void.  

void read_line(char *str, int n)
{	int ch, i = 0;
	while ((ch = getchar()) != '\n'){
		if (i < n){
			*str++ = ch;
			i++;
		}
	}
	*str = '\0'; //terminates string
	return;    //returns void
}

//extract will extract the name of the website that starts in www. and ends in
//.edu from the character array starting at the pointer s1 and will store the 
//result in the character array starting at the pointer s2.      

void extract(char *s1, char *s2)
{	char *p, *q, *r;  // p checks www., q writes to s2, r checks .edu
	for(p = s1, q = s2; *p != '\0'; p++){
		if((*p == 'w') && (*(p + 1) == 'w') && (*(p + 2) == 'w') && (*(p + 3) == '.')){ //steps forward and looks for www.
			break;  //p points to the . in www.
			}
		}
	if (s2 == '\0') return;  //checks if www. was recorded in s2, returns if false
	for(r = s1; *r != '\0'; r++){	//reads from the . in www. and looks for .edu
		if((*r == '.') && (*(r + 1) == 'e') && (*(r + 2) == 'd') && (*(r + 3) == 'u')){ //steps backwards and looks for .edu
			r += 3;				//sets r to point to the u in .edu
			while(p <= r){			//records everything between www. and .edu
				*q++ = *p++;
				}
			break;
			}
		}
	return;
}
