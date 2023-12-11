/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:47:13 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/11 20:47:08 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
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

char	*ft_strjoin(char const *s1, char const *s2, int size)
{
	size_t	total_len;
	char	*dest;
	int		x;
	int		y;

	if (!s2)
		return (NULL);
	total_len = ft_strlen(s1) + size;
	dest = (char *)malloc(sizeof(char) * (total_len));
	if (!dest)
		return (NULL);
	x = -1;
	y = 0;
	if (s1)
	{
		while (s1[++x])
			dest[x] = (char)s1[x];
	}
	else 
		x++;
	while (s2[y] && y < size)
		dest[x++] = (char)s2[y++];
	dest[x] = '\0';
	return (dest);
}
