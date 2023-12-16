/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:45:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/16 09:31:03 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	return (0);
}

static char	*ft_fill_zero(char *str)
{
	int	x;

	x = 0;
	while (x < BUFFER_SIZE + 1)
		str[x++] = '\0';
	return (str);
}

static char	*ft_read(int fd, char *stash)
{
	char		*line;
	long int	bytesRead;

	line = ft_strdup(stash);
	if (ft_contains_end_line(line) || line[0] == '\n')
		return (line);
	bytesRead = read(fd, stash, BUFFER_SIZE);
	if (bytesRead <= 0)
		return (free(line), NULL);
	while (bytesRead > 0)
	{
		stash[bytesRead] = '\0';
		line = ft_strnjoin(stash, line, bytesRead);
		if (ft_contains_end_line(line) != 0 || line[0] == '\n')
			break ;
		bytesRead = read(fd, line, BUFFER_SIZE);
		if (bytesRead < 0)
			return (NULL);
	}
	return (line);
}

static char	*ft_line(char *stash)
{
	char	*line;
	size_t	size;

	line = NULL;
	if (stash)
	{
		size = ft_contains_end_line(stash);
		line = ft_strnjoin(line, stash, size + 1);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	size_t		rest;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, stash, 0) < 0)
		return (NULL);
	line = ft_read(fd, stash);
	if (stash == NULL)
	{
		ft_fill_zero(stash);
		return (NULL);
	}
	if (ft_contains_end_line(stash) == 0 && stash[0] != '\n')
		return (stash);
	line = ft_line(line);
	rest = ft_contains_end_line(stash) + 1;
	if (rest > 0 && stash[rest])
		ft_strlcpy(stash, stash + rest, BUFFER_SIZE);
	else
		ft_fill_zero(stash);
	return (line);
}
