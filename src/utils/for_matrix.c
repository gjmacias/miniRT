#include "miniRT.h"

void	init_matrix(t_4Matrix *matrix)
{
	int	i;
	int	j;

	i = -1;
	while (++i != 4)
	{
		j = -1;
		while (++j != 4)
		{
			if (i == j)
				matrix->m[i][j] = 1.0f;
			else
				matrix->m[i][j] = 0.0f;
		}
	}
}

void	create_pos_matrix(t_4Matrix *matrix, t_camera *c)
{
	matrix->m[0][3] = c->center.x;
	matrix->m[1][3] = c->center.y;
	matrix->m[2][3] = c->center.z;
}

void	create_direction_matrix(t_4Matrix *matrix, t_camera *c)
{
	t_vector right, up, forward;

	forward = c->n_vector;
	right = cross_product((t_vector){0, 1, 0}, forward);
	right = normalize_v(right);
	up = cross_product(forward, right);
	up = normalize_v(up);
	matrix->m[0][0] = right.x;
	matrix->m[1][0] = right.y;
	matrix->m[2][0] = right.z;
	matrix->m[0][1] = up.x;
	matrix->m[1][1] = up.y;
	matrix->m[2][1] = up.z;
	matrix->m[0][2] = forward.x;
	matrix->m[1][2] = forward.y;
	matrix->m[2][2] = forward.z;
}
