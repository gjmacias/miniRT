/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_defs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacias- <gmacias-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:53:04 by gmacias-          #+#    #+#             */
/*   Updated: 2023/12/11 12:04:17 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DEFS_H
# define MINIRT_DEFS_H

# define ESC	53

# define BLACK 	0x00000000
# define RED	0x00FF0000
# define GREEN 	0x0000FF00
# define BLUE 	0x000000FF
# define WHITE	0x00FFFFFF

#define EPSILON 1e-6

# include "libft_defs.h"
# include <stddef.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bpps;
	int		l_len;
	int		endian;
	t_vars	vars;
}			t_mlx_data;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}		t_vector;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}		t_color;

typedef struct s_material
{
	t_color		color;
	double		specular;
}			t_material;

typedef struct s_camera
{
	t_vector	center;
	t_vector	n_vector;
	double		fov;
}				t_camera;

typedef struct s_light
{
	t_vector	center;
	double		brightness;
	t_color		color;
}				t_light;

typedef struct s_ambiental
{
	double		brightness;
	t_color		color;
}				t_ambiental;

typedef struct s_plane
{
	t_vector	center;
	t_vector	n_vector;
	t_material	material;
}				t_plane;

typedef struct s_sphere
{
	t_vector	center;
	double		diameter;
	double		r;
	double		r_sq;
	t_material	material;
}				t_sphere;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	n_vector;
	double		diameter;
	double		r;
	double		r_sq;
	double		height;
	t_material	material;
}				t_cylinder;

typedef struct s_info
{
	size_t	ambient_light;
	size_t	camera;
	size_t	lights;
	size_t	planes;
	size_t	spheres;
	size_t	cylinders;
}		t_info;

typedef struct s_data
{
	char		*txt;
	size_t		line;
	int			width;
	int			height;
	int			render_MIN;
	int			render_MAX;
	t_info		info;
	t_ambiental	ambient_light;
	t_camera	camera;
	t_list		*lights;
	t_list		*planes;
	t_list		*spheres;
	t_list		*cylinders;
}				t_data;

typedef struct s_4Matrix
{
	float	m[4][4];
}	t_4Matrix;

#endif
