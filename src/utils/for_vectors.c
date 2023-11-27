#include "miniRT.h"

float	angle_vectors(t_vector a, t_vector b)
{
	float	magnitude1;
	float	magnitude2;
	float	scalar;
	float	radians;

	magnitude1 = v_magnitude(a);
	magnitude2 = v_magnitude(b);
	scalar = scalar_product(a, b);
	radians = (acos(scalar / (magnitude1 * magnitude2)));
	return (radians);
}

t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}
