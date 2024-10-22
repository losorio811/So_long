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

void	put_image(t_window *win, int y, int x)
{
	if (map()->map[y][x] == 'P')
		mlx_put_image_to_window(win->mlx, win->win,
			win->textp, x * I, y * I);
	else if (map()->map[y][x] == 'C')
		mlx_put_image_to_window(win->mlx, win->win,
			win->textc, x * I, y * I);
	else if (map()->map[y][x] == 'E')
		mlx_put_image_to_window(win->mlx, win->win,
			win->texte, x * I, y * I);
}
