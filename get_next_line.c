/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:45:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/14 20:15:19 by mbernard         ###   ########.fr       */
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

char	*ft_fill_buff(char *buf)
{
	int	x;

	x = 0;
	while (x < BUFFER_SIZE + 1)
		buf[x++] = '\0';
	return (buf);
}

char	*ft_all(int fd, char *buf, char *stash)
{
	char	*all;
	int		bytesRead;

	all = NULL;
	if (fd && buf)
	{
		if (stash)
			all = ft_strnjoin(all, stash, ft_strlen(stash));
		bytesRead = 1;
		while (bytesRead > 0)
		{
			bytesRead = read(fd, buf, BUFFER_SIZE);
			if (bytesRead < 0)
				return (NULL);
	//		printf("BYTESREAD\t=\t%i\n", bytesRead);
			if (bytesRead > 0)
			{
				all = ft_strnjoin(all, buf, BUFFER_SIZE);
				buf[bytesRead] = '\0';
			}
			if(ft_contains_end_line(buf) != 0)
				break ;
		}
	}
	return (all);
}

char	*ft_line(char *all)
{
	char	*line;
	size_t	size;

	line = NULL;
	if (all)
	{
		size = ft_contains_end_line(all);
//		printf("SIZE OF LINE\t===\t%i\n", size);
		line = ft_strnjoin(line, all, size);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1] = "";
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	char		*all;
	size_t		rest;

	ft_fill_buff(buf);
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, buf, 0) < 0)
		return (NULL);
	all = ft_all(fd, buf, stash);
	line = ft_line(all);
	rest = ft_contains_end_line(buf) + 1;
	free(all);
	if (rest > 0 && buf[rest])
		ft_strlcpy(stash, buf + rest, BUFFER_SIZE);
	return (line);
}
