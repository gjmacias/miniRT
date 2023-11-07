#include <limits.h>
#include "libft.h"

double ft_strtod(char *str)
{
    size_t  n;
    size_t  i;
    double  result;

    n = ft_atoi(str);
    i = 0;
    while(str && str[i] != '.')
        i++;
    if(str[i] == '.')
        i++;
    result = (double)ft_atoi(&str[i]);
    result = result / pow(10, strlen(&str[i]));
    result = n + result;
    return (result);
}