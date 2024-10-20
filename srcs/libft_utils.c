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