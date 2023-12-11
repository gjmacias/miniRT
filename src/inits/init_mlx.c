/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:00:50 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/13 13:00:50 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "miniRT_defs.h"

void	init_mlx(t_mlx_data *d, t_data *p)
{
	d->vars.mlx = mlx_init();
	d->vars.win = mlx_new_window(d->vars.mlx, p->width, p->height, "miniRT");
	d->img = mlx_new_image(d->vars.mlx, p->width, p->height);
	d->addr = mlx_get_data_addr(d->img, &d->bpps, &d->l_len, &d->endian);
	mlx_put_image_to_window(d->vars.mlx, d->vars.win, d->img, 0, 0);
}
