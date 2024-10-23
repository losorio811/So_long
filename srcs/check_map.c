#include "../include/so_long.h"

void	ft_check_map(char *file)
{
	int	fd;

	fd = ft_open(file);
	if (fd < 0)
		ft_error("Error: Could not open the file\n");
	ft_read_file(fd);
	close(fd);
	fd = ft_open(file);
	ft_check_walls(fd);
	close(fd);
	fd = ft_open(file);
	ft_create_map(fd);
	close(fd);
	ft_pre_flood_fill(map()->map_copy);
}

void	ft_check_walls(int file)
{
	char	*str;
	size_t	line_size;

	str = get_next_line(file);
	line_size = 0;
	while (str[line_size] && str[line_size] != '\n')
		line_size++;
	ft_check_top_bottom(str);
	free(str);
	str = get_next_line(file);
	while (str)
	{
		if (str[line_size] == '\0')
			ft_check_top_bottom(str);
		else
			ft_check_middle(str, line_size);
		ft_map_char(str);
		free(str);
		str = get_next_line(file);
	}
	ft_check_char();
}

void	ft_check_top_bottom(char* line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			free(line);
			ft_error("Error: Invalid walls\n");
		}
		i++;
	}
}

void	ft_check_middle(char *line, int line_size)
{
	if (line[0] != '1' || line[line_size - 1] != '1')
	{
		free(line);
		ft_error("Error: Invalid walls\n");
	}
}

void	ft_create_map(int fd)
{
	int		i;
	char	*str;

	i = 0;
	map()->map = (char **)malloc((map()->rows + 1) * sizeof(char *));
	if (!map()->map)
		ft_error("Error: Memory allocation error\n");
	str = get_next_line(fd);
	while (str)
	{
		map()->map[i++] = str;
		str = get_next_line(fd);
	}
	map()->map[i] = NULL;
	ft_create_map_copy();
}
