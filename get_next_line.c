/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:45:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/15 17:59:45 by mbernard         ###   ########.fr       */
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

static char	*ft_fill_zero(char *buf)
{
	int	x;

	x = 0;
	while (x < BUFFER_SIZE + 1)
		buf[x++] = '\0';
	return (buf);
}

static char	*ft_all(int fd, char *buf, char *stash)
{
	char		*all;
	long int	bytesRead;

	all = NULL;
	all = ft_strnjoin(all, stash, ft_strlen(stash));
	if (ft_contains_end_line(all) || all[0] == '\n')
		return (all);
	bytesRead = read(fd, buf, BUFFER_SIZE);
	if (bytesRead <= 0)
		return (free(all), NULL);
	while (bytesRead > 0)
	{
		buf[bytesRead] = '\0';
		all = ft_strnjoin(all, buf, bytesRead);
		if (ft_contains_end_line(all) != 0 || all[0] == '\n')
			break ;
		bytesRead = read(fd, buf, BUFFER_SIZE);
		if (bytesRead < 0)
			return (NULL);
	}
	return (all);
}

static char	*ft_line(char *all)
{
	char	*line;
	size_t	size;

	line = NULL;
	if (all)
	{
		size = ft_contains_end_line(all);
		line = ft_strnjoin(line, all, size + 1);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	char		*all;
	size_t		rest;

	ft_fill_zero(buf);
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, buf, 0) < 0)
		return (NULL);
	all = ft_all(fd, buf, stash);
	if (all == NULL)
	{
		ft_fill_zero(stash);
		return (NULL);
	}
	if (ft_contains_end_line(all) == 0 && all[0] != '\n')
		return (all);
	// ft_putendl("ALL");
	//	ft_putendl(all);
	line = ft_line(all);
	rest = ft_contains_end_line(buf) + 1;
	free(all);
	if (rest > 0 && buf[rest])
	{
		ft_strlcpy(stash, buf + rest, BUFFER_SIZE);
//		ft_putendl("STASH BEGIN");
	//	ft_putendl(stash);
//		ft_putendl("STASH END");
	}
	else
		ft_fill_zero(stash);
	return (line);
}

