#include "miniRT.h"

void	camera(void)
{
	t_vector	right;
	t_vector	up;

	right = cross_product(vector_up, direction);
	up = cross_product(direction, right);
}
