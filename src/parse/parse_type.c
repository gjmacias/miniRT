/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:01:30 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/19 16:58:01 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "miniRT_defs.h"
#include "libft.h"

void	p_ambient_ligth(char **arguments, t_data *p)
{
	p->info.ambient_light += 1;
	if (p->info.ambient_light > 1)
		write_error3("Error: ambient light < ", arguments[0],
			" > is DUPLICATED\n");
	input_brightness(arguments[1], p, &(p->ambient_light.brightness));
	input_color(arguments[2], p, &(p->ambient_light.color));
	if (arguments[3])
		write_error3int("Error in line: < ", p->line,
			" > too many arguments\n");
}

void	p_camera(char **arguments, t_data *p)
{
	p->info.camera += 1;
	if (p->info.camera > 1)
		write_error3("Error: camera < ", arguments[0],
			" > is DUPLICATED\n");
	p->camera->center = ft_calloc(1, sizeof(t_vector));
	if (!p->camera->center)
		clean_exit(p, 12);
	input_position(arguments[1], p, p->camera->center);
	p->camera->n_vector = ft_calloc(1, sizeof(t_vector));
	if (!p->camera->n_vector)
		clean_exit(p, 12);
	input_vector(arguments[2], p, p->camera->n_vector);
	input_fov(arguments[3], p, &(p->camera->fov));
	if (arguments[4])
		write_error3int("Error in line: < ", p->line,
			" > too many arguments\n");
}

void	parse_type_error(char **arguments, t_data *p)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	ft_putstr_fd("Error: < ", 2);
	ft_putstr_fd(arguments[0], 2);
	ft_putstr_fd(" > in line: < ", 2);
	ft_putstr_fd(line_num, 2);
	ft_putstr_fd(" > is a invalid input\n", 2);
	free(line_num);
	exit(EXIT_FAILURE);
}

void	parse_type(char **arguments, t_data *p)
{
	if (ft_strlen(arguments[0]) == 1)
	{
		if (ft_strncmp("A", arguments[0], 2) == 0)
			p_ambient_ligth(arguments, p);
		else if (ft_strncmp("C", arguments[0], 2) == 0)
			p_camera(arguments, p);
		else if (ft_strncmp("L", arguments[0], 2) == 0)
			p_ligths(arguments, p);
		else
			parse_type_error(arguments, p);
	}
	else if (ft_strlen(arguments[0]) == 2)
	{
		if (ft_strncmp("pl", arguments[0], 3) == 0)
			p_plane(arguments, p);
		else if (ft_strncmp("sp", arguments[0], 3) == 0)
			p_sphere(arguments, p);
		else if (ft_strncmp("cy", arguments[0], 3) == 0)
			p_cylinder(arguments, p);
		else
			parse_type_error(arguments, p);
	}
	else
		parse_type_error(arguments, p);
}
