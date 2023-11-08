#include "libft.h"
#include <math.h>

double	ft_strtod(char *str)
{
	size_t	n;
	size_t	i;
	double	result;

	n = ft_atoi(str);
	i = 0;
	while (str && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	result = (double)ft_atoi(&str[i]);
	result = result / pow(10, ft_strlen(&str[i]));
	result = n + result;
	return (result);
}

int	ft_strtouc(char *str)
{
	size_t	n;

	n = ft_atoi(str);
	if (n > 255 || n < 0 || str[0] == ',' || str[0] == '\0')
		return (-1);
	return ((int)n);
}
