/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:26:10 by gmacias-          #+#    #+#             */
/*   Updated: 2023/11/06 17:15:53 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include "miniRT_defs.h"

// CHECKERS
void	check_format_dotrt(char *txt);
int		checker_double(char *s, char c);
int		checker_array_double(char *s);
int		checker_uchar(char *s);

// EXIT
int		ft_exit(t_data *data);

// ERROR
void	write_error(char *s1);
void	write_error3(char *s1, char *s2, char *s3);

// HOOKS
int		key_hook(int keycode, t_vars *vars);
int		finish_execution(void);

//  INITS
void	init_mlx(t_vars *vars, t_mlx_data *data);
void	init_parameters_info(t_data *p);

//  PARSE
void	parse_txt(t_data *p);
void	parse_type(char **arguments, t_data *p);
void	p_ligths(char **arguments, t_data *p);
void	p_plane(char **arguments, t_data *p);
void	p_sphere(char **arguments, t_data *p);
void	p_cylinder(char **arguments, t_data *p);

void	input_brightness(char *s, t_data *p, double *bright);
void	input_possition(char *s, t_data *p, t_vector *center);
void	input_vector(char *s, t_data *p, t_vector *vector);
void	input_diameter(char *s, t_data *p, double *diameter);
void	input_fov(char *s, t_data *p, double *fov);
void	input_height(char *s, t_data *p, double *height);
void	input_color(char *s, t_data *p, t_color *color);

//  UTILS
int		is_space(int c);
double	ft_strtod(char *str);
int		ft_strtouc(char *str);
void	arraytouchar(char *s, t_color *color);
void	arraytodouble(char *s, t_vector *vector);

//  TEST
void	printaux(void);
void	printpp(char **s);
void	print_data(t_data *d);

#endif
