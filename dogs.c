//This program simulates a database at a veternary clinic for dogs.  It includes
//a structure for a dog including the number (patient number), dog name, last
//name of the owner and a dog breed.  The structure makes up a linked list of 
//data. 
//By Rachel Klesius

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NAME_LEN 30
struct dog{
	int number;
	char dog_name[NAME_LEN+1];
	char owner_last_name[NAME_LEN+1];
	char breed[NAME_LEN+1];
	struct dog *next;
};


struct dog *append(struct dog *list);
void search(struct dog *list);
void print(struct dog *list);
void clear(struct dog *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct dog *dog_list = NULL;  
  printf("Operation Code: a for appending to the list, s for finding a dog"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': dog_list = append(dog_list);
                break;
      case 's': search(dog_list);
                break;
      case 'p': print(dog_list);
                break;
      case 'q': clear(dog_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

//append asks the user to enter the patient number, dog's name, dog's breed, and
//owner's last name and then adds the dog to the end of the linked list.  This
//function tests if the dog already exists by patient number and exists if found.
//If the dog doesn't exist, the function allocates memory for the dog and adds
//it to the end of the linked list.  If the list is empty, the function returns
//a pointer to the new dog.  This function returns a pointer to the linked list.
struct dog *append(struct dog *list)
{	struct dog *temp; //dog to be inputted
	struct dog *p;

	//allocate space for new dog temp
	temp = malloc(sizeof(struct dog));
		if(temp == NULL){
			printf("malloc failed\n");
			return list;
			}

	printf("Enter patient number: ");
	scanf(" %d", &temp->number);
	printf("Enter the dog's name: ");
	read_line(temp->dog_name, NAME_LEN);
	printf("Enter the owner's last name: ");
	read_line(temp->owner_last_name, NAME_LEN);
	printf("Enter the dog's breed: ");
	read_line(temp->breed, NAME_LEN);
	temp->next = NULL; //since end of list, next dog is NULL

	//search if dog already exists
	for(p = list; p != NULL; p = p->next){
		if(p->number == temp->number){
			printf("Dog already exists");
			free(temp);
			return p;
			}
		}

	//if temp is the first dog in list
	if (list == NULL){
		return temp; //returns temp as list, since only member
		}

	//input dog in if not first dog
	for(p = list; p != NULL; p = p->next)  //sets p to the last dog
		if (p->next == NULL)
			break;
	p->next = temp; //connects the last item in list to temp
	return list;
}

//Search finds the dog by name and prints all the information with that name.
//If the dog is not found, it will print a message.  
void search (struct dog *list)
{	char temp_name[NAME_LEN + 1];
	struct dog *p;
	printf("Enter the dog's name: ");
	read_line(temp_name, NAME_LEN + 1);
	
	for (p = list; p != NULL; p = p->next){
		if((strcmp(p->dog_name, temp_name)) == 0){
			printf("Number: %d\n", p->number);
			printf("Dog name: %s\n", p->dog_name);
			printf("Owner's last name: %s\n", p->owner_last_name);
			printf("Breed: %s\n", p->breed);
			return;
		}
	}
	printf("Dog not found\n");
	return;

}

//print prints the entire linked list database of dogs.
void print(struct dog *list)
{
	struct dog *p;
	for (p = list; p != NULL; p = p->next){
		printf("Number: %d\n", p->number);
		printf("Dog name: %s\n", p->dog_name);
	}
	return;

}

//clear deallocates all the memory allocated for the linked list before the 
//program terminates.  
void clear(struct dog *list)
{
	struct dog *p;
	while(list != NULL){
		p = list;
		list = list->next;
		if (p != NULL)
			free(p);
	}
	return;

}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
 }
