
typedef struct s_point
{
	int	x;
	int y;
	int z;
}	t_point ;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color ;

typedef struct s_camera
{
	t_point	center;
	t_point	view_point;
	t_point	n_vector;
	int		fov;
}	t_camera ;

typedef struct s_light
{
	t_point	center;
	int		brightness;
	t_color	color;
}	t_light ;

typedef struct s_plane
{
	t_point	center;
	t_point	n_vector;
	t_color	color;
}	t_plane ;

typedef struct s_sphere
{
	t_point	center;
	t_point	n_vector;
	int		diameter;
	t_color	color;
}	t_sphere ;

typedef struct s_cylinder
{
	t_point	center;
	t_point	n_vector;
	int		diameter;
	int		height;
	t_color	color;
}	t_cylinder ;

typedef struct s_data
{
	t_light		ambient_light;
	t_camera	camera;
	t_light		*lights;
	t_plane		*planes;
	t_sphere	*spheres;
	t_cylinder	*cylinders;
}	t_data ;
