/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:26:10 by gmacias-          #+#    #+#             */
/*   Updated: 2024/02/05 19:23:06 by ffornes-         ###   ########.fr       */
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
# include "miniRT_keys.h"

void		free_data(t_data *d);
void		clean_exit(t_data *d, unsigned char exit_code);
void		fail_check(void *content, t_data *p);
// CHECKERS
void		check_format_dotrt(char *txt);
int			checker_double(char *s, char c);
int			checker_array_double(char *s);
int			checker_uchar(char *s);
int			checker_fov(char *s, char c);

// EXIT
int			ft_exit(t_data *data);

// ERROR
void		write_error(char *s1);
void		write_error3int(char *s1, int i, char *s3);
void		write_error3(char *s1, char *s2, char *s3);

// HOOKS
int			key_hook(int keycode, t_vars *vars);
int			key_hook_test(int keycode, t_hook *hook);
int			finish_execution(void);

//  INITS
void		init_mlx(t_mlx_data *d, t_data *p);
void		init_parameters_info(t_data *p);
void		init_canvas(t_data *p, char *str_width, char *str_height);
void		init_quaternion(t_vector *v, t_quaternion *q);
void		init_euler(t_vector *euler);
void		init_matrix(t_4Matrix *matrix);
void		init_itsc(t_itsc *itsc);

//  INPUTS
t_4Matrix	pos_camera(t_camera *c);

void		render_camera(t_data *d, t_mlx_data *mlx, int start, int end);
void		process_camera(t_data *d, t_mlx_data *mlx, int num);

//  PARSE
void		parse_txt(t_data *p);
void		parse_type(char **arguments, t_data *p);
void		p_lights(char **arguments, t_data *p);
void		p_plane(char **arguments, t_data *p);
void		p_sphere(char **arguments, t_data *p);
void		p_cylinder(char **arguments, t_data *p);

void		input_brightness(char *s, t_data *p, double *bright);
void		input_position(char *s, t_data *p, t_vector *center);
void		input_vector(char *s, t_data *p, t_vector *vector);
void		input_diameter(char *s, t_data *p, double *diameter);
void		input_fov(char *s, t_data *p, double *fov);
void		input_height(char *s, t_data *p, double *height);
void		input_color(char *s, t_data *p, t_color *color);

//	RAY TRACING
t_color		trace_ray(t_vector *ray, t_data *d);
t_color		calc_ambient(t_material *m, t_ambiental a);

//	UTILS
int			is_space(int c);

void		my_mlx_pixel_put(t_mlx_data *data, int x, int y, t_color color);

void		arraytouchar(char *s, t_color *color);
void		arraytodouble(char *s, t_vector *vector);

t_vector	ptop_vector(t_vector end, t_vector start);
t_vector	change_angle(t_vector vec, double angle, char axis);

double		ft_strtod(char *str);
int			ft_strtouc(char *str);

t_vector	neg_vector(t_vector *v);
t_vector	calculate_ray_direction(int x, int y, t_data *d);

t_color		new_color(int r, int g, int b, int a);
t_material	new_material(t_color color, double specular);

t_color		calc_light(t_material *m, t_light *l, double rad);

double		quadratic_formula(double a, double b, double c);
//  TEST
void		print_matrix(t_4Matrix *m);

void		printaux(void);
void		printpp(char **s);
void		print_data(t_data *d);
void		print_vector(t_vector vector);
void		print_color(t_color color);
void		printd(double d);
void		print_quaternion(t_quaternion quaternion);
void		print_ang(t_vector vector);

#endif
