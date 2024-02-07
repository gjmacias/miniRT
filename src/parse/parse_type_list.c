/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:01:40 by gmacias-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/19 18:25:48 by ffornes-         ###   ########.fr       */
=======
/*   Updated: 2024/02/05 19:24:07 by ffornes-         ###   ########.fr       */
>>>>>>> intersection_operations
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include "vectors.h"
#include "libft.h"

void	p_lights(char **arguments, t_data *p)
{
	t_list		*lst;
	t_light		*new;

	lst = ft_calloc(1, sizeof(t_list));
	fail_check(lst, p);
	new = ft_calloc(1, sizeof(t_light));
	fail_check(new, p);
	p->info.lights += 1;
	input_position(arguments[1], p, &new->center);
	input_brightness(arguments[2], p, &new->brightness);
	input_color(arguments[3], p, &new->color);
	if (arguments[4])
		write_error3int("Error in line: < ", p->line,
			" > too many arguments\n");
	lst->content = (void *)new;
	lst->next = p->lights;
	p->lights = lst;
}

void	p_plane(char **arguments, t_data *p)
{
	t_list		*lst;
	t_plane		*new;

	lst = ft_calloc(1, sizeof(t_list));
	fail_check(lst, p);
	new = ft_calloc(1, sizeof(t_plane));
	fail_check(new, p);
	p->info.planes += 1;
	input_position(arguments[1], p, &(new->center));
	input_vector(arguments[2], p, &(new->n_vector));
	input_color(arguments[3], p, &(new->material.color));
	if (arguments[4])
		write_error3int("Error in line: < ", p->line,
			" > too many arguments\n");
	lst->content = (void *)new;
	lst->next = p->planes;
	p->planes = lst;
}

void	p_sphere(char **arguments, t_data *p)
{
	t_list		*lst;
	t_sphere	*new;

	lst = ft_calloc(1, sizeof(t_list));
	fail_check(lst, p);
	new = ft_calloc(1, sizeof(t_sphere));
	fail_check(new, p);
	p->info.spheres += 1;
	input_position(arguments[1], p, &(new->center));
	input_diameter(arguments[2], p, &(new->diameter));
	input_color(arguments[3], p, &(new->material.color));
	new->r_sq = pow((new->diameter / 2), 2);
	if (arguments[4])
		write_error3int("Error in line: < ", p->line,
			" > too many arguments\n");
	lst->content = (void *)new;
	lst->next = p->spheres;
	p->spheres = lst;
}

static void	cylinder_precomputes(t_cylinder *new)
{
	new->r_sq = pow((new->diameter / 2), 2);
	new->half_height = new->height / 2;
	new->top_center = v_product(&new->n_vector, new->half_height);
	new->bot_center = new->top_center;
	new->top_center = v_addition(&new->center, &new->top_center);
	new->bot_center = v_subtract(&new->center, &new->bot_center);
	new->i_n_vector = v_product(&new->n_vector, -1);
}

void	p_cylinder(char **arguments, t_data *p)
{
	t_list		*lst;
	t_cylinder	*new;

	lst = ft_calloc(1, sizeof(t_list));
	fail_check(lst, p);
	new = ft_calloc(1, sizeof(t_cylinder));
	fail_check(new, p);
	p->info.cylinders += 1;
	input_position(arguments[1], p, &(new->center));
	input_vector(arguments[2], p, &(new->n_vector));
	input_diameter(arguments[3], p, &(new->diameter));
	input_height(arguments[4], p, &(new->height));
	input_color(arguments[5], p, &(new->material.color));
	if (arguments[6])
		write_error3int("Error in line: < ", p->line, \
				" > too many arguments\n");
	cylinder_precomputes(new);
	lst->content = (void *)new;
	lst->next = p->cylinders;
	p->cylinders = lst;
}
