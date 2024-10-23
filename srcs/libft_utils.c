#include "../include/so_long.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (dest[len] && len < size)
		len++;
	i = 0;
	while (src[i] && (len + i + 1) < size)
	{
		dest[len + i] = src[i];
		i++;
	}
	return (len + i);
}

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		ft_error("Empty map\n");
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] && str2[i]) && (str1[i] == str2[i]))
		i++;
	return (str1[i] - str2[i]);
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

void	ft_write_moves(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2", 2);
		write(1, "147483648", 9);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_write_moves(-n);
	}
	else if (n > 9)
	{
		ft_write_moves(n / 10);
		ft_write_moves(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}
