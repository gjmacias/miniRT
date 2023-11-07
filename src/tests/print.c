#include<stdio.h>

void printpp(char **arg)
{
	int i = 0;

	if(arg)
	{
		while (arg[i])
		{
			printf("%s", arg[i++]);
			if (arg[i])
				printf("\t\t");
			else
				printf("(null)\n");
		}
	}
	else
		printf("(null)");
}
