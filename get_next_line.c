/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:45:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/11 17:04:39 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_contains_end_line(const char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}

static int	ft_count_chars(char *str)
{
	int	x;

	x = 0;
	while (str[x] && str[x] != '\n')
		x++;
	return (x);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		buf[BUFFER_SIZE];
	char		*line;
	int x;

	if (BUFFER_SIZE <= 0 || fd <= 0)
		return (NULL);
	x = 0;
	if (stash)
		ft_strjoin(line, stash, ft_strlen(stash));
	read(fd, buf, BUFFER_SIZE);
	while (!ft_contains_end_line(buf))
	{
		ft_strjoin(line, buf, BUFFER_SIZE);
		write(1, line, BUFFER_SIZE);
		write(1, "\n", 1);
		read(fd, buf, BUFFER_SIZE);
		x++;
	}
	ft_strjoin(line, buf, ft_count_chars(buf));
	ft_strjoin(stash, buf + ft_count_chars(buf), BUFFER_SIZE - ft_count_chars(buf));
	write(1, stash, ft_strlen(stash));
	return (line);
}
