#include <unistd.h>
#include <stdlib.h> 
#include "libft.h"

void	write_error(char *s1)
{
	write(2, s1, ft_strlen(s1));
	exit(EXIT_FAILURE);
}

void	write_error3(char *s1, char *s2, char *s3)
{
	write(2, s1, ft_strlen(s1));
	write(2, s2, ft_strlen(s2));
	write(2, s3, ft_strlen(s3));
	exit(EXIT_FAILURE);
}
