#include "../include/so_long.h"

void	ft_read_file(int fd)
{
	char	*str;
	int		j;

	j = 0;
	str = get_next_line(fd);
	map()->columns = ft_linelen(str);
	while(str)
	{
		ft_check_shape(str);
		free(str);
		str = get_next_line(fd);
		j++;
	}
	map()->rows = j;
}

int	ft_open(char *file)
{
	int	fd;
	fd = open(file, O_RDONLY);
	if (file < 0)
		ft_error("Error opening the file\n");
	return (fd);
}

void	ft_map_char(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == 'C' || str[i] == 'E' || str[i] == 'P')
		{
			if (str[i] == 'P')
				map()->starting_pos += 1;
			else if (str[i] == 'C')
				map()->collect += 1;
			else if (str[i] == 'E')
				map()->exit += 1;
		}
		else
		{
			free(str);
			ft_error("Invalid character\n");
		}
		i++;
	}
}

void	ft_check_char(void)
{
	if (map()->starting_pos != 1)
		ft_error("Error: Invalid number of starting position\n");
	if (map()->collect < 1)
		ft_error("Error: Missing collectables\n");
	if (map()->exit != 1)
		ft_error("Error: Invalid number of map exits\n");
}

void	ft_create_map_copy(void)
{
	int	i;

	i = 0;
	map()->map_copy = (char **)malloc(sizeof(char *) * (map()->rows + 1));
	if (!map()->map_copy)
	{
		ft_free_map(map()->map);
		ft_error("Memory allocation error\n");
	}
	while (map()->map[i])
	{
		//printf("%s\n", map()->map[i]);
		map()->map_copy[i] = ft_strdup(map()->map[i]);
		if (!map()->map_copy[i])
		{
			ft_free_map(map()->map);
			ft_free_map(map()->map_copy);
			ft_error("Memory allocation error\n");
		}
		free(map()->map[i]);
		i++;
	}
	map()->map_copy[i] = NULL;
	free(map()->map);
}