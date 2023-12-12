/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:47:13 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/12 15:32:10 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		write(1, &(s[len]), 1);
		len++;
	}
}

void	ft_putendl(char *s)
{
	ft_putstr(s);
	write(1, "\n", 1);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
	}
	return (len);
}

char	*ft_strjoin(char *s1, char *s2, size_t size)
{
	size_t	total_len;
	char	*dest;
	int		x;
	size_t		y;

	if (!s2)
		return (NULL);
	total_len = ft_strlen(s1) + size;
	dest = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!dest)
		return (NULL);
	x = 0;
	y = 0;
	if (s1)
	{
		while (s1[x])
		{
			dest[x] = (char)s1[x];
			x++;
		}
		free(s1);
	}
	while (s2[y] && y < size)
		dest[x++] = (char)s2[y++];
	dest[x] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	src_size;

	src_size = 0;
	if (size > 0)
	{
		while (src[src_size] && src_size < size - 1)
		{
			dest[src_size] = src[src_size];
			src_size++;
		}
		dest[src_size] = '\0';
	}
	while (src[src_size])
		src_size++;
	return (src_size);
}
