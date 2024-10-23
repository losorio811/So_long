#include "../include/so_long.h"

int	destroy(t_window *win)
{
	mlx_destroy_image(win->mlx, win->text0);
	mlx_destroy_image(win->mlx, win->text1);
	mlx_destroy_image(win->mlx, win->textp);
	mlx_destroy_image(win->mlx, win->textc);
	mlx_destroy_image(win->mlx, win->texte);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	ft_free_map(map()->map);
	exit(0);
	return (0);
}

void	check_if_collected(int keycode, int start_x, int start_y, t_window *win)
{
	static int	number_movements;

	if (keycode == KEY_A || keycode == KEY_D 
		|| keycode == KEY_W || keycode == KEY_S)
	{
		if (start_x != map()->starting_pos_x 
			|| start_y != map()->starting_pos_y)
		{
			number_movements += 1;
			ft_write_moves(number_movements);
			write(1, "\n", 1);
		}
	}
	if (map()->map[map()->starting_pos_y][map()->starting_pos_x] == 'C')
	{
		win->collected += 1;
		map()->map[map()->starting_pos_y][map()->starting_pos_x] = '0';
	}
	if ((win->collected == map()->collect) 
		&& map()->map[map()->starting_pos_y][map()->starting_pos_x] == 'E')
	{
		write(1, "WIN\n", 4);
		destroy(win);
	}
}

int	key_hook(int keycode, t_window *win)
{
	int		x;
	int		y;

	y = map()->starting_pos_y;
	x = map()->starting_pos_x;
	if (map()->map[y][x] != 'E')
		mlx_put_image_to_window(win->mlx, win->win,
			win->text0, x * ICON_SIZE, y * ICON_SIZE);
	if (keycode == KEY_ESC)
		destroy(win);
	if (keycode == KEY_A && map()->map[y][x - 1] != '1')
		map()->starting_pos_x -= 1;
	else if (keycode == KEY_D && map()->map[y][x + 1] != '1')
		map()->starting_pos_x += 1;
	else if (keycode == KEY_W && map()->map[y - 1][x] != '1')
		map()->starting_pos_y -= 1;
	else if (keycode == KEY_S && map()->map[y + 1][x] != '1')
		map()->starting_pos_y += 1;
	if (map()->map[map()->starting_pos_y][map()->starting_pos_x] != 'E')
		mlx_put_image_to_window(win->mlx, win->win, win->textp,
			map()->starting_pos_x * ICON_SIZE, map()->starting_pos_y * I);
	check_if_collected(keycode, x, y, win);
	return (0);
}

void	draw_bg(t_window *win)
{
	int		x;
	int		y;

	y = 0;
	while (map()->map[y])
	{
		x = 0;
		while (map()->map[y][x])
		{
			if (map()->map[y][x] == '1')
				mlx_put_image_to_window(win->mlx,
					win->win, win->text1, x * I, y * I);
			else
				mlx_put_image_to_window(win->mlx,
					win->win, win->text0, x * I, y * I);
			put_image(win, y, x);
			x++;
		}
		y++;
	}
}

void	init_mlx(void)
{
	static t_window		win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, map()->columns * I, map()->rows * I, "So_long");
	mlx_key_hook(win.win, key_hook, &win);
	mlx_hook(win.win, 17, 0L, destroy, &win);
	win.path0 = "./textures/0/floor.xpm";
	win.path1 = "./textures/1/wall.xpm";
	win.pathp = "./textures/P/player.xpm";
	win.pathc = "./textures/C/collect.xpm";
	win.pathe = "./textures/E/exit.xpm";
	win.text0 = mlx_xpm_file_to_image(win.mlx, win.path0,
			&win.width, &win.height);
	win.text1 = mlx_xpm_file_to_image(win.mlx, win.path1,
			&win.width, &win.height);
	win.textp = mlx_xpm_file_to_image(win.mlx, win.pathp,
			&win.width, &win.height);
	win.textc = mlx_xpm_file_to_image(win.mlx, win.pathc,
			&win.width, &win.height);
	win.texte = mlx_xpm_file_to_image(win.mlx, win.pathe,
			&win.width, &win.height);
	draw_bg(&win);
	mlx_loop(win.mlx);
}
