#include "libft.h"
#include "miniRT.h"

int	checker_double(char *s, char c)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while (s[i] == '+' || s[i] == '-' )
		i++;
	if (ft_isdigit(s[i]))
	{
    	while (ft_isdigit(s[i]) || s[i] == '.')
    	{
    		if (s[i] == '.' && !(ft_isdigit(s[i + 1])))
    			return (1);
    		else if (s[i] == '.')
    			dot++;
    		if (dot > 1)
    			return (1);
    		i++;
    	}
    	if (s[i] == '\0' || s[i] == c)
		    return (0);
	}
	return (1);
}

int	checker_array_double(char *s)
{
	int	x[5];
	int comma;

	x[0] = 0;
	x[4] = 1;
	x[1] = checker_double(s , ',');
	x[2] = 1;
	x[3] = 1;
	comma = 0;
	while (s[x[0]] != '\0')
	{
		if (s[x[0]] == ',')
		{
			comma++;
			if (comma > 2 || s[x[0] + 1] == ',' || s[x[0] + 1] == '\0')
				break ;
			x[4] += 1;
			x[x[4]] = checker_double(&s[x[0] + 1], ',');
		}
		x[0] += 1;
	}
	if (comma != 2 || x[1] == 1 || x[2] == 1 || x[3] == 1)
		return (1);
	return (0);
}

int	checker_array_uchar(char *s)
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
	if (x[1] == -1 || x[2] == -1 || x[3] == -1 || x[4] == -1)
		return (1);
	return (0);
}

int	checker_uchar(char *s)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (ft_isdigit(s[i]) || s[i] == ',')
	{
		if (s[i] == ',')
			comma++;
		i++;
	}
	if (s[i] != '\0' || comma > 3 || comma < 2)
		return (1);
	return (checker_array_uchar(s));
}

int	checker_fov(char *s, char c)
{
	double	result;

	if (checker_double(s, c))
		return (1);
	result = ft_strtod(s);
	if (result > 180.0 || result < 0.0)
		return (1);
	return (0);
}