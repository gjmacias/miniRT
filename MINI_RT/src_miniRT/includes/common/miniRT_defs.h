/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_defs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:53:04 by gmacias-          #+#    #+#             */
/*   Updated: 2024/02/05 16:56:30 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFS_H
# define MINIRT_DEFS_H

# define X			0
# define Y			1

# define PLANE		1
# define SPHERE		2
# define CYLINDER	3
# define TOP_CAP	4
# define BOT_CAP	5

# define BLACK 		0x00000000
# define RED		0x00FF0000
# define GREEN 		0x0000FF00
# define BLUE 		0x000000FF
# define WHITE		0x00FFFFFF

# define EPSILON 	1e-6

# include "libft_defs.h"
# include <stddef.h>

typedef struct s_4Matrix
{
	float	m[4][4];
}	t_4Matrix;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}		t_color;

typedef struct s_info
{
	unsigned char	ambient_light;
	unsigned char	camera;
	unsigned char	lights;
	unsigned char	planes;
	unsigned char	spheres;
	unsigned char	cylinders;
}		t_info;

typedef struct s_material
{
	t_color		color;
	double		specular;
}			t_material;

typedef struct s_ambiental
{
	t_color		color;
	double		brightness;
}				t_ambiental;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}		t_vector;

typedef struct s_quaternion
{
	double	x;
	double	y;
	double	z;
	double	w;
}		t_quaternion;

typedef struct s_camera
{
	double			fov;
	t_vector		*center;
	t_vector		*euler;
	t_quaternion	*q;
}				t_camera;

typedef struct s_light
{
	t_color		color;
	double		brightness;
	t_vector	center;
}				t_light;

typedef struct s_intersection
{
	unsigned char	type;
	void			*address;
	double			dist;
	t_vector		*p;
	t_vector		*normal;
	t_material		mat;
}	t_itsc;

typedef struct s_plane
{
	t_vector	center;
	t_vector	n_vector;
	t_material	material;
}				t_plane;

typedef struct s_sphere
{
	double		diameter;
	double		r_sq;
	t_vector	center;
	t_material	material;
}				t_sphere;

typedef struct s_mlx_data
{
	int		bpps;
	int		l_len;
	int		endian;
	void	*img;
	char	*addr;
	t_vars	vars;
}			t_mlx_data;

typedef struct s_cylinder
{
	double		diameter;
	double		r_sq;
	double		half_height;
	double		height;
	t_vector	center;
	t_vector	top_center;
	t_vector	bot_center;
	t_vector	n_vector;
	t_vector	i_n_vector;
	t_material	material;
}				t_cylinder;

typedef struct s_data
{
	int			width;
	int			height;
	t_info		info;
	size_t		line;
	char		*txt;
	t_list		*lights;
	t_list		*planes;
	t_list		*spheres;
	t_list		*cylinders;
	t_camera	*camera;
	t_ambiental	ambient_light;
}				t_data;

typedef struct s_hook
{
	t_mlx_data	*data;
	t_data		*parameters;
}			t_hook;
#endif
