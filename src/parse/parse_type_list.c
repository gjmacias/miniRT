/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:01:40 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/19 18:25:48 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include "libft.h"

void	p_ligths(char **arguments, t_data *p)
{
	t_list	*new_list;
	t_light	*new_content;

	new_list = malloc(sizeof(t_list));
	new_content = malloc(sizeof(t_light));
	if (new_content == NULL || new_list == NULL)
		clean_exit(p, 12);
	p->info.lights += 1;
	new_content->center = ft_calloc(1, sizeof(t_vector));
	if (!new_content->center)
		clean_exit(p, 12);
	input_position(arguments[1], p, new_content->center);
	input_brightness(arguments[2], p, &(new_content->brightness));
	input_color(arguments[3], p, &(new_content->color));
	if (arguments[4])
		write_error3int("Error in line: < ", p->line,
			" > too many arguments\n");
	new_list->content = (void *)new_content;
	new_list->next = p->lights;
	p->lights = new_list;
}

void	p_plane(char **arguments, t_data *p)
{
	t_list	*new_list;
	t_plane	*new_content;

	new_list = malloc(sizeof(t_list));
	new_content = malloc(sizeof(t_plane));
	if (new_content == NULL || new_list == NULL)
		clean_exit(p, 12);
	p->info.planes += 1;
	new_content->center = ft_calloc(1, sizeof(t_vector));
	if (!new_content->center)
		clean_exit(p, 12);
	input_position(arguments[1], p, new_content->center);
	new_content->n_vector = ft_calloc(1, sizeof(t_vector));
	if (!new_content->n_vector)
		clean_exit(p, 12);
	input_vector(arguments[2], p, new_content->n_vector);
	input_color(arguments[3], p, &(new_content->material.color));
	if (arguments[4])
		write_error3int("Error in line: < ", p->line,
			" > too many arguments\n");
	new_list->content = (void *)new_content;
	new_list->next = p->planes;
	p->planes = new_list;
}

void	p_sphere(char **arguments, t_data *p)
{
	t_list		*new_list;
	t_sphere	*new_content;

	new_list = malloc(sizeof(t_list));
	new_content = malloc(sizeof(t_sphere));
	if (new_content == NULL || new_list == NULL)
		clean_exit(p, 12);
	p->info.spheres += 1;
	new_content->center = ft_calloc(1, sizeof(t_vector));
	if (!new_content->center)
		clean_exit(p, 12);
	input_position(arguments[1], p, new_content->center);
	input_diameter(arguments[2], p, &(new_content->diameter));
	input_color(arguments[3], p, &(new_content->material.color));
	new_content->r_sq = pow((new_content->diameter / 2), 2);
	if (arguments[4])
		write_error3int("Error in line: < ", p->line,
			" > too many arguments\n");
	new_list->content = (void *)new_content;
	new_list->next = p->spheres;
	p->spheres = new_list;
}

void	p_cylinder(char **arguments, t_data *p)
{
	t_list		*new_list;
	t_cylinder	*new_content;

	new_list = malloc(sizeof(t_list));
	new_content = malloc(sizeof(t_cylinder));
	if (new_content == NULL || new_list == NULL)
		clean_exit(p, 12);
	p->info.cylinders += 1;
	new_content->center = ft_calloc(1, sizeof(t_vector));
	if (!new_content->center)
		clean_exit(p, 12);
	new_content->top_center = ft_calloc(1, sizeof(t_vector));
	if (!new_content->top_center)
		clean_exit(p, 12);
	new_content->bot_center = ft_calloc(1, sizeof(t_vector));
	if (!new_content->bot_center)
		clean_exit(p, 12);
	new_content->n_vector = ft_calloc(1, sizeof(t_vector));
	if (!new_content->n_vector)
		clean_exit(p, 12);
	new_content->i_n_vector = ft_calloc(1, sizeof(t_vector));
	if (!new_content->i_n_vector)
		clean_exit(p, 12);

	input_position(arguments[1], p, new_content->center);
	input_vector(arguments[2], p, new_content->n_vector);
	input_diameter(arguments[3], p, &(new_content->diameter));
	input_height(arguments[4], p, &(new_content->height));
	input_color(arguments[5], p, &(new_content->material.color));
	if (arguments[6])
		write_error3int("Error in line: < ", p->line,
			" > too many arguments\n");

	new_content->r_sq = pow((new_content->diameter / 2), 2);
	new_content->half_height = new_content->height / 2;

	*new_content->top_center = v_product(new_content->n_vector, new_content->half_height);
	*new_content->bot_center = *new_content->top_center;

	*new_content->top_center = v_addition(new_content->center, new_content->top_center);
	*new_content->bot_center = v_subtract(new_content->center, new_content->bot_center);

	*new_content->i_n_vector = v_product(new_content->n_vector, -1);

	new_list->content = (void *)new_content;
	new_list->next = p->cylinders;
	p->cylinders = new_list;
}
