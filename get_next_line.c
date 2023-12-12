/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:45:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/12 15:59:30 by mbernard         ###   ########.fr       */
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
	static char	stash[BUFFER_SIZE + 1] = "";
	char		buf[BUFFER_SIZE];
	char		*line;
	size_t			rest;
	int			bytesRead;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	line = ft_strjoin(line, stash, ft_strlen(stash));
	bytesRead = read(fd, buf, BUFFER_SIZE);
	if (bytesRead < 0)
		return (free(line), NULL);
	while (bytesRead > 0 && ft_contains_end_line(buf) == 0)
	{
		line = ft_strjoin(line, buf, BUFFER_SIZE);
		bytesRead = read(fd, buf, BUFFER_SIZE);
	}
	rest = ft_count_chars(buf);
	if (rest > 0)
	{
		line = ft_strjoin(line, buf, rest);
		ft_strlcpy(stash, buf + rest, BUFFER_SIZE - rest);
	}
	return (line);
}
