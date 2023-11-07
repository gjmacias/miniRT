#ifndef MINIRT_DEFS_H
# define MINIRT_DEFS_H

# define ESC	53
# define WIDTH	1920
# define HEIGHT	1080

# define BLACK 	0x00000000
# define RED	0x00FF0000
# define GREEN 	0x0000FF00
# define BLUE 	0x000000FF
# define WHITE	0x00FFFFFF

# include "libft_defs.h"

typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bpps;
	int		l_len;
	int		endian;
}			t_mlx_data;

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
	t_vector	view_point;
	t_vector	n_vector;
	int			fov;
}				t_camera;

typedef struct s_light
{
	t_vector	center;
	double		brightness;
	t_color		color;
}				t_light;

typedef struct s_plane
{
	t_vector	center;
	t_vector	n_vector;
	t_material	material;
}				t_plane;

typedef struct s_sphere
{
	t_vector	center;
	t_vector	n_vector;
	double		diameter;
	t_material	material;
}				t_sphere;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	n_vector;
	double		diameter;
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
	t_info		info;
	t_light		ambient_light;
	t_camera	camera;
	t_list		*lights;
	t_list		*planes;
	t_list		*spheres;
	t_list		*cylinders;
}				t_data;

#endif
