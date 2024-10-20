#include "../include/so_long.h"

void	ft_error(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	exit(0);
}

void	ft_free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_check_shape(char *str)
{
	if (ft_linelen(str) != map()->columns)
	{
		free(str);
		ft_error("Error: Map is not a rectangle\n");
	}
}

t_map	*map(void)
{
	static t_map	map;

	return (&map);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ptr;
	int		size;

	i = 0;
	size = ft_strlen(str);
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}