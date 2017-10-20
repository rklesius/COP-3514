//dogs.c contains all the functions used in records.c and the function
//prototypes and macro definitions are in dogs.h.  
//By Rachel Klesius

#include "dogs.h"
#include "readline.h"

/************************************************************
 * append: Prompts the user for informaiton about a dog and *
 * then append the dog structure to the end of the list.    *
 * Prints an error message and returns prematurely  if the  *
 * dog already exists by its patient number or memory       *
 * could not be allocated for the dog structure.            *
 * *********************************************************/

struct dog *append(struct dog *list){
  struct dog *cur, *new_node;

  new_node = malloc(sizeof(struct dog));
  if (new_node == NULL) {
    printf("Database is full; can't add more dogs.\n");
    return list;
  }

  printf("Enter dog's patient number: ");
  scanf("%d", &new_node->number);

  for (cur = list;cur != NULL;cur = cur->next)
  if (cur != NULL && new_node->number == cur->number) {
    printf("Patient already exists.\n");
    free(new_node);
    return list;
  }

  printf("Enter dog's  name: ");
  read_line(new_node->dog_name, NAME_LEN);
  printf("Enter dog's breed: ");
  read_line(new_node->breed, NAME_LEN);
  printf("Enter owner's last name: ");
  read_line(new_node->owner_last_name, NAME_LEN);
  new_node->next = NULL;

  if(list == NULL)
  {
        list = new_node;
        return list;
  }
  else{
   for(cur = list; cur->next!= NULL; cur = cur->next);
     cur->next = new_node;
     return list;
 }

}

/***********************************************************
 * search: Prompts the user to enter a dog's name, then    *
 * looks up dog(s) by name in the list. Prints the all the *
 * informaiton of the dogs with the name if found.         *
 * Otherwise, prints a message.                            *
 * ********************************************************/

void search (struct dog *list)
{
  char search_name[NAME_LEN+1];
  struct dog *p;
  int found =0;
  printf("Enter dog's name: ");
  read_line(search_name, NAME_LEN);

  for(p=list;
       p != NULL;
       p = p->next)
  {
   if(strcmp(search_name, p->dog_name)==0){
    	found = 1;
    	printf("%d\t", p->number);
	printf("%s\t", p->dog_name);
    	printf("%s\t", p->breed);
    	printf("%s\n", p->owner_last_name);
    }
  } 
  if(!found)
    printf("dog not found.\n");

}

/************************************************************
 * print: Prints a listing of all dogs in the list, showing *
 * the dog's patient number, name, breed, and owner's last  *
 * name.                                                    *
 * *********************************************************/

void print(struct dog *list){

  struct dog *p;

  printf("Dog Number\tDog Name\t"
         "Dog Breed\tOwner Last Name\n");
  for (p = list; p != NULL; p = p->next)
    printf("%d\t\t%s\t\t%s\t\t%s\n", p->number, p->dog_name,p->breed,
           p->owner_last_name);

}
/***************************************************************
 * clear: Clears the entire linked list. It begins at the head * 
 * of the list and frees memory allocated for each node of the *
 * linked list.                                                *
 * ************************************************************/

void clear(struct dog *list)
{
  struct dog *p;

  while(list!=NULL)
  {
         p = list;
         list = list->next;
         if(p!=NULL)
            free(p);
  }

}


