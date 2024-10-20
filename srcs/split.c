#include "../include/so_long.h"

void	*ft_free(char **strs, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(strs[i]);
		i++;
	}
	free(strs[i]);
	return (NULL);
}

int	ft_line_count(const char *s, char c)
{
	size_t	i;
	size_t	num;

	i = 0;
	num = 0;
	while (s[i] && s[i] == c)
		i++;
	if (s[i])
		num++;
	while (s[i] && s[i] != c)
		i++;
	return (num);
}

int	ft_str_size(const char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_str_alloc(const char *s, char c)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_str_size(s, c);
	str = (char *)malloc(sizeof(char *) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	i;

	i = 0;
	strs = (char **)malloc(sizeof(char *) * ft_line_count(s, c));
	if (strs == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			strs[i] = ft_str_alloc(s, c);
			if (strs[i] == NULL)
				return (ft_free(strs, i));
			i++;
		}
		while(*s && *s != c)
			s++;
	}
	strs[i] = NULL;
	return (strs);
}