
#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>

# define KEY_ESC 65307
# define ICON_SIZE 40
# define I 40
# define KEY_A 97
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100

typedef struct s_map
{
	int		exit;
	int		collect;
	int		starting_pos;
	int		columns;
	int		rows;
	char	**map;
	char	**map_copy;
	int		starting_pos_x;
	int		starting_pos_y;
	int		collect_temp;
	int		exit_temp;
	int		position_temp;
}		t_map;

int		ft_strcmp(char *str1, char *str2);
int		ft_linelen(char *str);
void	ft_check_args(int ac, char *av[]);
void	ft_check_map(char *file);
void	ft_error(char *str);
int		ft_open(char *file);
void	ft_read_file(int fd);
void	ft_check_shape(char *str);
t_map	*map(void);
void	ft_check_walls(int fd);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	**ft_split(const char *s, char c);
void	ft_check_top_bottom(char *line);
void	ft_check_middle(char *line, int line_size);
void	ft_free_map(char **str);
void	ft_pre_flood_fill(char **map);
void	ft_map_char(char *str);
void	ft_check_char(void);
void	ft_create_map(int fd);
void	ft_create_map_copy(void);
char	*ft_strdup(char *str);

#endif