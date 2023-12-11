/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:45:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/11 20:54:57 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_contains_end_line(const char *str)
{
	int	x;

	x = 0;
	if (str)
	{
		while (str[x])
		{
			if (str[x] == '\n')
				return (1);
			x++;
		}
	}
	return (0);
}

static int	ft_count_chars(char *str)
{
	int	x;

	x = 0;
	if (str)
	{
		while (str[x] != '\n')
			x++;
	}
	return (x);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buf[BUFFER_SIZE];
	char		*line;
	int			x;
	int			rest;

	if (BUFFER_SIZE <= 0 || fd <= 0 || read(fd, buf, 0) == 0)
		return (NULL);
	x = 0;
	if (stash)
		ft_strjoin(line, stash, ft_strlen(stash));
	read(fd, buf, BUFFER_SIZE);
	while (!ft_contains_end_line(buf))
	{
		line = ft_strjoin((const char *)line, (const char *)buf, BUFFER_SIZE);
		read(fd, buf, BUFFER_SIZE);
		x++;
	}
	rest = ft_count_chars(buf);
	line = ft_strjoin(line, buf, rest);
	stash = ft_strjoin(stash, buf + rest, BUFFER_SIZE - rest);
	//write(1, stash, ft_strlen(stash));
	return (line);
}
