//including libraries
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
	D_list *head_1 = NULL, *tail_1 = NULL;
	D_list *head_2 = NULL, *tail_2 = NULL;
	D_list *head_out = NULL, *tail_out = NULL;
	int i = 0;
	char operator, op1, op2;

	if ( argc == 4 )
	{
		if ( strcmp(argv[3], "+") == 0 )
		{
			printf("Arbitary_precision_calculator\n");
			i = valid_args(argv[1], &op1);
			while(argv[1][i])
			{
				if ( insert_at_last(&head_1, &tail_1, argv[1][i] - 48) == SUCCESS )
				{
					i++;	
				}
				else
					return FAILURE;
			}
			i = valid_args(argv[2], &op2);
			while(argv[2][i])
			{
				if ( insert_at_last(&head_2, &tail_2, argv[2][i] - 48) == SUCCESS )
				{
					i++;	
				}
				else
					return FAILURE;
			}
			print_list(head_1);
			print_list(head_2);
		}
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
	else
	{
		printf("INFO : ERROR\n");
		printf("USAGE : ./a.out 34 26 +\n");
	}

	return 0;
}

int insert_at_last(D_list **head, D_list **tail, int data)
{
	D_list *new = malloc(sizeof(D_list));

	if ( new == NULL )
		return FAILURE;

	new->prev = NULL;
	new->data = data;
	new->next = NULL;

	if ( *head == NULL && *tail == NULL )
	{
		*head = new;
		*tail = new;

		return SUCCESS;
	}

	(*tail)->next = new;
	new->prev = *tail;
	*tail = new;

	return SUCCESS;
}


void print_list(D_list *head)
{
	if ( head == NULL )
		printf("INFO : List is empty\n");

	else
	{
		printf("Head -> ");
		while(head)
		{
			printf("%d <-", head->data);
			head = head->next;
			if ( head )
				printf("> ");
		}
		printf(" Tail\n");
	}
}

int valid_args(char *argv, char *op)
{
	return OP_NOT_FOUND;
}
