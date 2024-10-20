/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loosorio <loosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:37:33 by loosorio          #+#    #+#             */
/*   Updated: 2024/01/30 19:39:37 by loosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	line = NULL;
	i = 0;
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while (buf[i])
			buf[i] = '\0';
		return (NULL);
	}
	while ((buf[0]) || read(fd, buf, BUFFER_SIZE) > 0)
	{
		line = ft_joinbuf(line, buf);
		if (ft_cleanbuf(buf) == 1)
			break ;
	}
	return (line);
}
