/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:33:50 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/02 15:33:50 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <minirt.h>

int  main(int words, char**arguments)
{
	t_info_map	data;

	if (words == 2)
	{
		data.mlx = mlx_init();
		ft_reset_data(&data, arguments[1]);
		ft_malloc_map(&data);
		ft_general_check(&data);
		data.win = mlx_new_window(data.mlx, data.width * 40,
				data.hight * 40, "so_long");
		mlx_hook(data.win, 17, 0, ft_exit, &data);
	}
	else
		write(2, "Error: Bad arguments\n", 22);
	return (0);
}
