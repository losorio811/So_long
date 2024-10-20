#include "../include/so_long.h"

void	ft_flood_fill(int x, int y)
{
	if (map()->map_copy[y][x] == '1')
		return ;
	map()->collect_temp += (map()->map_copy[y][x] == 'C');
	map()->exit_temp += (map()->map_copy[y][x] == 'E');
	map()->position_temp += (map()->map_copy[y][x] == 'P');
	map()->map_copy[y][x] = '1';
	ft_flood_fill(x + 1, y);
	ft_flood_fill(x - 1, y);
	ft_flood_fill(x, y + 1);
	ft_flood_fill(x, y - 1);
}

void	ft_check_pos_and_fill(char **map_copy, int y)
{
	int	x;

	x = 0;
	while(map_copy[y][x])
	{
		if (map_copy[y][x] == 'P')
		{
			map()->starting_pos_x = x;
			map()->starting_pos_y = y;
			ft_flood_fill(map()->starting_pos_x, map()->starting_pos_y);
			if (!(map()->collect == map()->collect_temp 
				&& map()->exit == map()->exit_temp 
				&& map()->starting_pos == map()->position_temp))
			{
				ft_free_map(map()->map_copy);
				ft_free_map(map()->map);
				ft_error("Error: Impossible to find a valid path\n");
			}
			return ;
		}
		x++;
	}
}

void	ft_pre_flood_fill(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		ft_check_pos_and_fill(map, y);
		y++;
	}
	ft_free_map(map);
}
