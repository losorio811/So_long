
#include "../include/so_long.h"

void	ft_check_args(int ac, char *av[])
{
	int	i;

	if (ac < 2)
		ft_error("Not enough arguments\n");
	if (ac > 2)
		ft_error("To many arguments\n");
	i = 0;
	while (av[1][i])
		i++;
	i -= 4;
	if (ft_strcmp(&av[1][i], ".ber"))
		ft_error("Wrong type of file\n");
}

int main(int ac, char *av[])
{
	if (I < 1)
	{
		write(1, "Invalid size\n", 13);
	}
	ft_check_args(ac, av);
	ft_check_map(av[1]);
	init_mlx();
	return (0);
}
