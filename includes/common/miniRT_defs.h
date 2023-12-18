/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_defs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:53:04 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/18 18:30:26 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFS_H
# define MINIRT_DEFS_H

# define X			0
# define Y			1

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

//	1 1 1 1								= 4 bytes
typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}		t_color;

//	4 8									= 12 bytes
typedef struct s_material
{
	t_color		color;
	double		specular;
}			t_material;

//	4 8									= 12 bytes
typedef struct s_ambiental
{
	t_color		color;
	double		brightness;
}				t_ambiental;

//	8 8									= 16 bytes
typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

//	8 12								= 20 bytes
typedef struct s_intersection
{
	double		dist;
	t_material	mat;
}	t_intersection;

//	8 8 8 8								= 32 bytes
typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}		t_vector;

//	4 8 32								= 44 bytes
typedef struct s_light
{
	t_color		color;
	double		brightness;
	t_vector	center;
}				t_light;

//	4 4 4 8 8 16						= 44 bytes
typedef struct s_mlx_data
{
	int		bpps;
	int		l_len;
	int		endian;
	void	*img;
	char	*addr;
	t_vars	vars;
}			t_mlx_data;

//	8 8 8 8 8 8							= 48 bytes
typedef struct s_info
{
	size_t	ambient_light;
	size_t	camera;
	size_t	lights;
	size_t	planes;
	size_t	spheres;
	size_t	cylinders;
}		t_info;

//	8 8 8 12 32							= 68 bytes
typedef struct s_sphere
{
	double		diameter;
	double		r;
	double		r_sq;
	t_material	material;
	t_vector	center;
}				t_sphere;

//	8 32 32								= 72 bytes
typedef struct s_camera
{
	double		fov;
	t_vector	center;
	t_vector	n_vector;
}				t_camera;

//	12 32 32							= 76 bytes
typedef struct s_plane
{
	t_material	material;
	t_vector	center;
	t_vector	n_vector;
}				t_plane;

//	8 8 8 8 12 32 32 					= 108 bytes
typedef struct s_cylinder
{
	double		diameter;
	double		r;
	double		r_sq;
	double		height;
	t_material	material;
	t_vector	center;
	t_vector	n_vector;
}				t_cylinder;

//	1 4 4 4 4 8 12 16 16 16 16 48 72	= 221 bytes
typedef struct s_data
{
	char		*txt;
	int			width;
	int			height;
	int			render_min;
	int			render_max;
	size_t		line;
	t_ambiental	ambient_light;
	t_list		*lights;
	t_list		*planes;
	t_list		*spheres;
	t_list		*cylinders;
	t_info		info;
	t_camera	camera;
}				t_data;

//	44 221								= 265 bytes
typedef struct s_hook
{
	t_mlx_data	*data;
	t_data		*parameters;
}			t_hook;
#endif
