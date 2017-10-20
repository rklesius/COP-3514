//This program takes a message inputed by the user, removes all punctuation 
//(nonletters) except white spaces, brings all letters to uppercase, and then
//prints the message.
//By Rachel Klesius

#include <stdio.h>

int main(void){
	char ch;
	printf("Please enter a message: ");
	do{
		ch = getchar();
		if ((ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || (ch == ' '))
			printf("%c", ch);
		if (ch >= 'a' && ch <= 'z'){
			ch = ch - 'a' + 'A';
			printf("%c", ch);
			}
	} while (ch != '\n');
	printf("\n");
	return 0;
}
