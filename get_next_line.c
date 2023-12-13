/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:45:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/13 18:38:15 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_contains_end_line(char *str)
{
	int	x;

	x = 0;
	while (str && str[x])
	{
	//	write(1, &str[x], 1);
		if (str[x] == '\n')
			return (x);
		x++;
	}
	return (0);
}

char	*ft_all(int fd, char *buf, char *stash)
{
	char	*all;
	int		bytesRead;

	all = NULL;
	if (fd && buf)
	{
		if (stash)
			all = ft_strjoin(all, stash, ft_strlen(stash));
		bytesRead = read(fd, buf, BUFFER_SIZE);
		if (bytesRead < 0)
			return (NULL);
		buf[BUFFER_SIZE + 1] = '\0';
		while (bytesRead > 0 && ft_contains_end_line(buf) == 0)
		{
			/*
		ft_putendl("\nft_contains_end_line(buf)");
		printf("\n The FREAKING BUF :\t%i\n", ft_contains_end_line(buf));
		ft_putendl("\nBUFFER");
			
			*/
			all = ft_strjoin(all, buf, BUFFER_SIZE);
			bytesRead = read(fd, buf, BUFFER_SIZE);
			if (bytesRead > 0)
			{
				buf[BUFFER_SIZE] = '\n';
				buf[BUFFER_SIZE + 1] = '\0';// PROBS TO COME
			}
		}
		if (bytesRead > 0)
			all = ft_strjoin(all, buf, BUFFER_SIZE);
	//	ft_putendl(buf);
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
		size = ft_contains_end_line(all) + 1;
		line = ft_strjoin(line, all, size);
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

	buf[0] = '\0';
	if (BUFFER_SIZE <= 0 || fd <= 0 || read(fd, buf, 0) < 0)
		return (NULL);
	all = ft_all(fd, buf, stash);
	line = ft_line(all);
	free(all);
	rest = ft_contains_end_line(buf) + 1;
	if (rest > 0 && buf[rest])
	{
		ft_strlcpy(stash, buf + rest, BUFFER_SIZE);
		//ft_putendl(stash);
	}
	return (line);
}
