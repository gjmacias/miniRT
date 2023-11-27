/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inputs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:01:10 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/13 13:01:10 by gmacias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"

void	input_fov(char *s, t_data *p, double *fov)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_double(s, '\0'))
	{
		ft_putstr_fd("Error in line: < ", 2);
		ft_putstr_fd(line_num, 2);
		if (s)
			ft_putstr_fd(" > Bad parameter: Double FOV\n", 2);
		else
			ft_putstr_fd(" > Need parameter: FOV\n", 2);
		exit(EXIT_FAILURE);
	}
	if (checker_fov(s, '\0'))
	{
		write_error3("Error in line: < ", line_num, " > Bad parameter: FOV\n");
		exit(EXIT_FAILURE);
	}
	(*fov) = ft_strtod(s);
	free(line_num);
}

void	input_height(char *s, t_data *p, double *height)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_double(s, '\0'))
	{
		ft_putstr_fd("Error in line: < ", 2);
		ft_putstr_fd(line_num, 2);
		if (s)
			ft_putstr_fd(" > Bad parameter: Double height\n", 2);
		else
			ft_putstr_fd(" > Need parameter: height\n", 2);
		exit(EXIT_FAILURE);
	}
	(*height) = ft_strtod(s);
	free(line_num);
}

void	input_color(char *s, t_data *p, t_color *color)
{
	char	*line_num;

	line_num = ft_itoa(p->line);
	if (!s || checker_uchar(s))
	{
		ft_putstr_fd("Error in line: < ", 2);
		ft_putstr_fd(line_num, 2);
		if (s)
			ft_putstr_fd(" > Bad parameter: Vector color\n", 2);
		else
			ft_putstr_fd(" > Need parameter: color\n", 2);
		exit(EXIT_FAILURE);
	}
	arraytouchar(s, color);
	free(line_num);
}
