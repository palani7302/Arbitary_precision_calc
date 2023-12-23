#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1

typedef struct list
{
	int data;
	struct list *prev;
	struct list *next;
}D_list;

int insert_at_last(D_list **, D_list **, int);
void print_list(D_list *);
int valid_args(char *, char *, int *);

#endif
