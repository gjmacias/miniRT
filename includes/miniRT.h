/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:26:10 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/11 14:49:45 by ffornes-         ###   ########.fr       */
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

//  INPUTS
t_4Matrix	pos_camera(t_camera *c);

void		render_camera(t_data *d, t_mlx_data *mlx);
void		init_canvas(t_data *p, char *str_width, char *str_height);

//  PARSE
void		parse_txt(t_data *p);
void		parse_type(char **arguments, t_data *p);
void		p_ligths(char **arguments, t_data *p);
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
t_color		trace_ray(t_vector ray, t_data *d);

//	UTILS
void		arraytouchar(char *s, t_color *color);
void		arraytodouble(char *s, t_vector *vector);

void		init_matrix(t_4Matrix *matrix);
void		create_pos_matrix(t_4Matrix *matrix, t_camera *c);
void		create_direction_matrix(t_4Matrix *matrix, t_camera *c);
void		create_FOV_matrix(t_4Matrix *matrix, double fov);
t_vector 	matrix_FOV(t_4Matrix *m, t_data *d, t_vector v);

float		angle_vectors(t_vector a, t_vector b);
t_vector	cross_product(t_vector a, t_vector b);

double		ft_strtod(char *str);
int			ft_strtouc(char *str);

double		rayhit_plane(t_vector ray0, t_vector ray_dir, t_plane *plane);

int			is_space(int c);

void		my_mlx_pixel_put(t_mlx_data *data, int x, int y, t_color color);

t_vector	*new_vector(double x, double y, double z);

t_vector	normalize_v(t_vector vector);
t_vector	v_FOV(int x, int y, t_data *d);

t_vector	v_addition(t_vector v1, t_vector v2);
t_vector	v_subtract(t_vector v1, t_vector v2);
t_vector	v_product(t_vector v1, double n);
double		v_magnitude(t_vector vector);

double		dot(t_vector v1, t_vector v2);

double		rayhit_pl(t_vector ray0, t_vector ray_dir, t_plane *plane);
double		rayhit_sp(t_vector ray0, t_vector ray_dir, t_sphere *sp);
double		rayhit_cy(t_vector ray0, t_vector ray_dir, t_cylinder *cy);

//  TEST
void		print_matrix(t_4Matrix *m);

void		printaux(void);
void		printpp(char **s);
void		print_data(t_data *d);
void		print_vector(t_vector vector);
void		print_color(t_color color);

#endif
