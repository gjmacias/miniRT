#include "libft.h"
#include "get_next_line.h"
#include "miniRT.h"
#include "miniRT_defs.h"

void print(char **arg)
{
	int i = 0;

	if(arg)
	{
		while (arg[i])
		{
			printf("%s", arg[i++]);
			if(arg[i])
				printf("\t\t");
			else
				printf("\n");
		}
		
	}
}


void	fill_expected_line(char *line, char *s)
{
	int	i;

	i = 0;
	while (line && line[i] != '\0')
	{
		while (is_space(line[i]))
			i++;
		while (!(is_space(line[i])) && line[i] != '\0')
		{
			s[i] = line[i];
			i++;
		}
		if (line[i] != '\0' && is_space(line[i]))
			s[i] = ' ';
	}
}

char	*correct_spaces(char *line)
{
	char	*s;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (line && line[i] != '\0')
	{
		while (is_space(line[i]))
			i++;
		while (!(is_space(line[i])) && line[i] != '\0')
		{
			i++;
			len++;
		}
		if (line[i] != '\0' && is_space(line[i]))
		{
			len++;
			i++;
		}
	}
	s = ft_calloc(sizeof(char), len + 1);
	fill_expected_line(line, s);
	return (s);
}

void	search_from(char* line, t_data *p)
{
	char	**arguments;
	char	*expected_line;

	expected_line = correct_spaces(line);
	arguments = ft_split(expected_line, ' ');
	print(arguments);
	(void)p;
}

void	parse_txt(t_data *p)
{
	char	*line;
	int		fd;

	fd = open(p->txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error: Map not read\n", 21);
		exit (EXIT_FAILURE);
	}
	while (line)
	{
		search_from(line, p);
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
	exit (EXIT_SUCCESS);
}
