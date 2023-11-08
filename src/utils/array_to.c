#include "libft.h"
#include "miniRT.h"
#include "miniRT_defs.h"

void	arraytouchar(char *s, t_color *color)
{
	int	x[6];

	x[0] = 0;
	x[5] = 1;
	x[4] = 255;
	x[1] = ft_strtouc(s);
	while (s[x[0]] != '\0')
	{
		if (s[x[0]] == ',')
		{
			x[5] += 1;
			x[x[5]] = ft_strtouc(&s[x[0] + 1]);
		}
		x[0] += 1;
	}
	color->r = x[1];
	color->g = x[2];
	color->b = x[3];
	color->a = x[4];
}

void	arraytodouble(char *s, t_vector *vector)
{
	int	x[5];

	x[0] = 0;
	x[4] = 1;
	x[1] = checker_double(s, ',');
	while (s[x[0]] != '\0')
	{
		if (s[x[0]] == ',')
		{
			x[4] += 1;
			x[x[4]] = checker_double(&s[x[0] + 1], ',');
		}
		x[0] += 1;
	}
	vector->x = x[1];
	vector->y = x[2];
	vector->z = x[3];
}
