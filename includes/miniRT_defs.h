#ifndef MINIRT_DEFS_H
# define MINIRT_DEFS_H

typedef struct s_vector
{
	int	x;
	int	y;
	int	z;
}		t_vector;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}		t_color;

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
	int			brightness;
	t_color		color;
}				t_light;

typedef struct s_plane
{
	t_vector	center;
	t_vector	n_vector;
	t_color		color;
}				t_plane;

typedef struct s_sphere
{
	t_vector	center;
	t_vector	n_vector;
	int			diameter;
	t_color		color;
}				t_sphere;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	n_vector;
	int			diameter;
	int			height;
	t_color		color;
}				t_cylinder;

typedef struct s_info
{
	int	ambient_light;
	int	lights;
	int	planes;
	int	spheres;
	int	cylinders;
}		t_info;

typedef struct s_data
{
	t_info		info;
	t_light		ambient_light;
	t_camera	camera;
	t_light		*lights;
	t_plane		*planes;
	t_sphere	*spheres;
	t_cylinder	*cylinders;
}				t_data;

#endif
