#include "miniRT_defs.h"

void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, t_color color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpps / 8));
	*(unsigned int *)dst = color.r; //esto esta mal
}
