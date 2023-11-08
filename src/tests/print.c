#include<stdio.h>

void printpp(char **arguments)
{
	int i = 0;

	if(arguments)
	{
		while (arguments[i])
		{
			printf("%s", arguments[i++]);
			if (arguments[i])
				printf("\t\t");
			else
				printf("(null)\n");
		}
	}
	else
		printf("(null)");
}
