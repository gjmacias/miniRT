#include <minirt.h>

void	ft_bad_malloc(void)
{
	write(2, "Error\nMap not malloc\n", 21);
	exit (EXIT_FAILURE);
}

void	ftsearch(t_info_map *data)
{
	char	*line;
	int		fd;

	fd = open(data->txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error\nMap not read\n", 19);
		exit (EXIT_FAILURE);
	}
	while (line)
	{
		search_from(line);
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

void	ft_malloc_map(t_info_map *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(data->txt, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof (char *) * (data->hight + 1));
	if (!data->map)
		ft_bad_malloc();
	while (i < data->hight)
	{
		line = get_next_line(fd);
		if (!line)
			ft_bad_malloc();
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			ft_bad_malloc();
		data->map[i][data->width] = '\0';
		i++;
		free(line);
	}
	data->map[i] = NULL;
	close(fd);
}
