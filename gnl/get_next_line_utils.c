/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loosorio <loosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:49:51 by loosorio          #+#    #+#             */
/*   Updated: 2024/01/30 19:50:15 by loosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_checknl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
		{
			str[i] = '\0';
			break ;
		}
	}
	return (str);
}

char	*ft_joinbuf(char *line, char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(line) + ft_strlen(buf) + 1);
	if (!str)
		return (NULL);
	while (line && line[i])
	{
		str[i] = line[i];
		i++;
	}
	free(line);
	while (buf[j])
		str[i++] = buf[j++];
	str[i] = '\0';
	return (ft_checknl(str));
}

int	ft_cleanbuf(char *buf)
{
	int	i;
	int	j;
	int	nl;

	i = 0;
	j = 0;
	nl = 0;
	while (buf[i])
	{
		if (nl == 1)
			buf[j++] = buf[i];
		if (buf[i] == '\n')
			nl = 1;
		buf[i] = '\0';
		i++;
	}
	return (nl);
}
