#include "miniRT_defs.h"

int rgba_to_hex(t_color color)
{
	int	hex_color;

	hex_color = ((int)color.a << 24) | ((int)color.r << 16)
		| ((int)color.g << 8) | (int)color.b;
	return (hex_color);
}


void	my_mlx_pixel_put(t_mlx_data *data, int x, int y, t_color color)
{
	int		hex_color;
	char	*dst;

	hex_color = rgba_to_hex(color);
	dst = data->addr + (y * data->l_len + x * (data->bpps / 8));
	*(unsigned int *)dst = hex_color;
}
