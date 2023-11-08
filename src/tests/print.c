#include <stdio.h>

void	printaux()
{
	printf("paso por aqui\n");
}

void	printpp(char **arguments)
{
	int	i;

	i = 0;
	if (arguments)
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
