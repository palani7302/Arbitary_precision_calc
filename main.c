//including libraries
#include <stdio.h>

/*
Name			: Palani M
Date			:
Title			:
Sample Input	:
Sample output	:
 */

int main(int argc, char *argv[])
{

	if ( argc == 4 )
	{
		printf("Arbitary_precision_calculator\n");
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

