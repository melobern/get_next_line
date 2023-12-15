/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:47:13 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/15 18:04:41 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	size_t	total_len;
	char	*dest;
	size_t	x;
	size_t	y;

	if (!s2)
		return (NULL);
	total_len = ft_strlen(s1) + size;
	dest = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!dest)
		return (NULL);
	x = 0;
	y = 0;
	while (s1 && s1[x])
	{
		dest[x] = (char)s1[x];
		x++;
	}
	free(s1);
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
