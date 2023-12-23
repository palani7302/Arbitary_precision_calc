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
	int i = 0, ind;
	char operator, op1, op2;

	if ( argc == 4 )
	{
		if ( strcmp(argv[3], "+") == 0  || strcmp(argv[3], "-") == 0 || strcmp(argv[3], "x") == 0 || strcmp(argv[3], "/") == 0 )
		{
			printf("Arbitary_precision_calculator\n");

			i = valid_args(argv[1], &op1, &ind);

			if ( i == FAILURE )
			{
				return FAILURE;
			}
			else if ( i == SUCCESS )
			{
				while(argv[1][ind])
				{
					if ( insert_at_last(&head_1, &tail_1, argv[1][ind] - 48) == SUCCESS )
					{
						ind++;	
					}
					else
						return FAILURE;
				}
			}

			i = valid_args(argv[2], &op2, &ind);

			if ( i == FAILURE )
			{
				return FAILURE;
			}
			else
			{
				while(argv[2][ind])
				{	
					if ( insert_at_last(&head_2, &tail_2, argv[2][ind] - 48) == SUCCESS )
					{
						ind++;	
					}
					else
						return FAILURE;
				}
			}
			
			print_list(head_1);
			print_list(head_2);
		}
		else
		{
			printf("INFO : ERROR\n");
			printf("USAGE : ./a.out 34 26 +\n");
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

int valid_args(char *argv, char *op, int *ind)
{
	int i = 0;
	if (argv[0] == '+')
	{
		*op = '+';
		*ind = 1;
		i = 1;
	}
	else if ( argv[0] == '-')
	{
		*op = '-';
		*ind = 1;
		i = 1;
	}
	else if ( argv[0] >= '0' && argv[0] <= '9' )
	{
		*op = 0;
		*ind = 0;
		i = 0;
	}
	else
	{
		printf("Invalid operator\n");
		return FAILURE;
	}

	while ( argv[i] )
	{
		if ( argv[i] >= '0' && argv[i] <= '9' )
		{
			i++;
		}
		else
		{
			printf("Invalid number\n");
			return FAILURE;
		}
	}
	return SUCCESS;
}