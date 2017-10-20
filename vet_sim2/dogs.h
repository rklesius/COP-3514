//dogs.h is a header file for the source file dogs.c and is used in records.c
//By Rachel Klesius

#ifndef DOGS_H

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

/*function prototypes*/
struct dog *append(struct dog *list);
void search(struct dog *list);
void print(struct dog *list);
void clear(struct dog *list);
struct dog* delete_from_list(struct dog *dogs);

#endif
