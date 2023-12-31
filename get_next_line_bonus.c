/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:45:35 by mbernard          #+#    #+#             */
/*   Updated: 2024/01/02 08:19:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_contains_end_line(char *str)
{
	int	x;

	x = 0;
	while (str && str[x])
	{
		if (str[x] == '\n')
			return (x);
		x++;
	}
	return (-1);
}

static char	*ft_read(int fd, char *stash, char *line)
{
	long int	bytes_read;

	if (stash[0])
		line = ft_strnjoin(line, stash, BUFFER_SIZE);
	if (line == NULL)
		return (NULL);
	if (stash[0] && ft_contains_end_line(stash) != -1)
		return (line);
	bytes_read = read(fd, stash, BUFFER_SIZE);
	if (bytes_read <= 0 && !line[0])
		return (free(line), NULL);
	while (bytes_read > 0)
	{
		stash[bytes_read] = '\0';
		if (ft_contains_end_line(stash) != -1)
			break ;
		line = ft_strnjoin(line, stash, bytes_read);
		if (line == NULL)
			return (NULL);
		bytes_read = read(fd, stash, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
	}
	return (line);
}

static char	*ft_line(char *stash, char *line)
{
	int		size;
	int		len;
	char	*new;

	if (!line)
		return (NULL);
	len = ft_contains_end_line(line);
	if (len != -1)
	{
		new = ft_calloc(1, 1);
		new = ft_strnjoin(new, line, len + 1);
		return (free(line), new);
	}
	else if (stash[0])
	{
		size = ft_contains_end_line(stash) + 1;
		line = ft_strnjoin(line, stash, size);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	stash[1024][BUFFER_SIZE + 1];
	char		*line;
	int			rest;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, stash, 0) < 0)
	{
		if (fd > 0)
			stash[fd][0] = '\0';
		return (NULL);
	}
	line = ft_calloc(1, 1);
	line = ft_read(fd, stash[fd], line);
	line = ft_line(stash[fd], line);
	if (line == NULL)
	{
		stash[fd][0] = '\0';
		return (NULL);
	}
	rest = ft_contains_end_line(stash[fd]) + 1;
	if (rest > 0 && stash[fd][rest - 1])
		ft_strncpy(stash[fd], stash[fd] + rest, BUFFER_SIZE);
	else
		stash[fd][0] = '\0';
	return (line);
}
