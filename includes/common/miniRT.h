/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:26:10 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/21 18:32:04 by ffornes-         ###   ########.fr       */
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

void		render_camera(t_data *d, t_mlx_data *mlx, int start, int end);
void		process_camera(t_data *d, t_mlx_data *mlx, int num);
void		init_canvas(t_data *p, char *str_width, char *str_height);
void		init_quaternion(t_vector *v, t_quaternion *q);


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
t_color		trace_ray(t_vector *ray, t_data *d);

//	MATRIX
t_color		calc_ambient(t_material *m, t_ambiental a);

void		init_matrix(t_4Matrix *matrix);
void		create_pos_matrix(t_4Matrix *matrix, t_camera *c);
void		create_direction_matrix(t_4Matrix *matrix, t_camera *c);
void			create_FOV_matrix(t_4Matrix *matrix, double fov);
t_vector 		matrix_FOV(t_4Matrix *m, t_data *d, t_vector *v);
t_vector		rotate_vector_by_quaternion(t_vector v, t_quaternion q);
t_quaternion	rotate_quaternion(double angle_degrees, int c);
t_quaternion	multiply_quaternions(t_quaternion q1, t_quaternion q2);
t_quaternion	euler_to_quaternion(double yaw, double pitch, double roll);



//	VECTORS
t_vector	new_vector(double x, double y, double z);
t_vector	tmp_vector(double x, double y, double z);

t_vector	v_addition(t_vector *v1, t_vector *v2);
t_vector	v_subtract(t_vector *v1, t_vector *v2);
t_vector	v_product(t_vector *v1, double n);
double		v_magnitude(t_vector *vector);
void		normalize_v(t_vector *vector);
double		dot(t_vector *v1, t_vector *v2);
float		angle_vectors(t_vector *a, t_vector *b);
t_vector	cross_product(t_vector *a, t_vector *b);

//	INTERSECTIONS
double		rayhit_pl(t_vector *ray0, t_vector *ray_dir, t_plane *plane);
double		rayhit_sp(t_vector *ray0, t_vector *ray_dir, t_sphere *sp);
double		rayhit_cy(t_vector *ray0, t_vector *ray_dir, t_cylinder *cy);
t_vector	get_itsc_p(t_vector *ray_dir, t_vector *ray0, double t);
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

//  TEST
void		print_matrix(t_4Matrix *m);

void		printaux(void);
void		printpp(char **s);
void		print_data(t_data *d);
void		print_vector(t_vector vector);
void		print_color(t_color color);
void		printd(double d);
void		print_quaternion(t_quaternion quaternion);


#endif
