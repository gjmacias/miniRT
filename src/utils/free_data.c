/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:41:24 by ffornes-          #+#    #+#             */
/*   Updated: 2023/12/19 17:05:34 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_bonus.h"
#include "miniRT_defs.h"
#include <stdlib.h>

static void	free_geo(t_data *d, t_list *aux)
{
	aux = d->planes;
	while (aux)
	{
		free(((t_plane *)aux->content)->center);
		free(((t_plane *)aux->content)->n_vector);
		aux = aux->next;
	}
	if (d->planes)
		ft_lstclear(&d->planes, NULL);
	aux = d->spheres;
	while (aux)
	{
		free(((t_sphere *)aux->content)->center);
		aux = aux->next;
	}
	if (d->spheres)
		ft_lstclear(&d->spheres, NULL);
	aux = d->cylinders;
	while (aux)
	{
		free(((t_cylinder *)aux->content)->center);
		aux = aux->next;
	}
	if (d->cylinders)
		ft_lstclear(&d->cylinders, NULL);
}

void	free_data(t_data *d)
{
	t_list	*aux;

	if (d->camera->center)
		free(d->camera->center);
	if (d->camera->euler)
		free(d->camera->euler);
	if (d->camera->q)
		free(d->camera->q);
	free(d->camera);
	aux = d->lights;
	while (aux)
	{
		free(((t_light *)aux->content)->center);
		aux = aux->next;
	}
	if (d->lights)
		ft_lstclear(&d->lights, NULL);
	free_geo(d, aux);
}

void	clean_exit(t_data *d, unsigned char exit_code)
{
	free_data(d);
	if (exit_code == 12)
		ft_putstr_fd("miniRT: Error: Failed malloc, not enough memory\n", 2);
	exit(exit_code);
}
