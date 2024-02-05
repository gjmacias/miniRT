/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:41:24 by ffornes-          #+#    #+#             */
/*   Updated: 2024/02/05 18:56:12 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"
#include "miniRT_defs.h"
#include <stdlib.h>

void	free_data(t_data *d)
{
	if (d->camera->center)
		free(d->camera->center);
	if (d->camera->euler)
		free(d->camera->euler);
	if (d->camera->q)
		free(d->camera->q);
	free(d->camera);
	if (d->lights)
		ft_lstclear(&d->lights, NULL);
	if (d->planes)
		ft_lstclear(&d->planes, NULL);
	if (d->spheres)
		ft_lstclear(&d->spheres, NULL);
	if (d->cylinders)
		ft_lstclear(&d->cylinders, NULL);
}

void	clean_exit(t_data *d, unsigned char exit_code)
{
	free_data(d);
	if (exit_code == 12)
		ft_putstr_fd("miniRT: Error: Failed malloc, not enough memory\n", 2);
	exit(exit_code);
}

void	fail_check(void *content, t_data *p)
{
	if (!content)
		clean_exit(p, 12);
}
