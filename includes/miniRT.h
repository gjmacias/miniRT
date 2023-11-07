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

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "miniRT_defs.h"

// CHECKERS
void	check_format_dotrt(char *txt);
void	checker_main(char **arguments);

// EXIT
int		ft_exit(t_data *data);

// HOOKS
int		key_hook(int keycode, t_vars *vars);
int		finish_execution(void);

//  INITS
void	init_mlx(t_vars *vars, t_mlx_data *data);
void	init_parameters_info(t_data *p);

//  PARSE
void	parse_txt(t_data *p);
void	parse_type(char **arguments, t_data *p);
void	p_plane(char **arguments, t_data *p);
void	p_sphere(char **arguments, t_data *p);
void	p_clinder(char **arguments, t_data *p);

void	input_brightness(char *arg, t_data *p);
void	input_possition(char *arg, t_data *p);
void	input_vector(char *arg, t_data *p);
void	input_diameter(char *arg, t_data *p);
void	input_fov(char *arg, t_data *p);
void	input_height(char *arg, t_data *p);
void	input_color(char *arg, t_data *p);

//  UTILS
int		is_space(int c);
double	ft_strtod(char *str);
int		ft_strtouc(char *str);

//  TEST
void	printpp(char **arg);
