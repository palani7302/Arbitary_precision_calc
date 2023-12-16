//including libraries
#include <stdio.h>
#include "main.h"

/*
Name			: Palani M
Date			:
Title			:
Sample Input	:
Sample output	:
 */

int main(int argc, char *argv[])
{
	D_list *head = NULL, *tail = NULL, *node;
	node = malloc(sizeof(D_list));
	if ( node == NULL )
	{
		return 1;
	}

	node->data = 25;

	if ( argc == 4 )
	{
		printf("Arbitary_precision_calculator\n");
		printf("Number is %d\n", node->data);
	}
	else if ( argc < 4 )
	{
		printf("INFO : Less no. of arguments\n");
		printf("USAGE : ./a.out 34 26 +\n");
	}
	else if ( argc > 4 )
	{
		printf("INFO : Too many arguments\n");
		printf("USAGE : ./a.out 34 26 +\n");
	}

	return 0;
}

