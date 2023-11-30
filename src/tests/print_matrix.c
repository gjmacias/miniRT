#include "miniRT_defs.h"
#include <stdio.h>

void	print_matrix(t_4Matrix *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i != 4)
	{
		j = -1;
		while (++j != 4)
		{
			printf("[ %.4f ]\t", m->m[i][j]);
		}
		printf("\n");
	}
}
