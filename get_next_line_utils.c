/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:47:13 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/21 20:09:27 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*copy;
	unsigned char	*ptr;
	size_t			count;

	if (nmemb && size && ((nmemb * size) / nmemb != size))
		return (NULL);
	size = nmemb * size;
	count = 0;
	copy = (void *)malloc(size);
	if (!(copy))
		return (NULL);
	ptr = (unsigned char *)copy;
	while (count < size)
	{
		ptr[count] = (unsigned char)0;
		count++;
	}
	return (ptr);
}

char	*ft_strnjoin(char *s1, char *s2, size_t size)
{
	size_t	total_len;
	char	*dest;
	size_t	x;
	size_t	y;

	if (!s1)
		return (NULL);
	if (!s2)
		return (free(s1), NULL);
	total_len = ft_strlen(s1) + size;
	dest = (char *)malloc((total_len + 1) * sizeof(char));
	if (!dest)
		return (free(s1), NULL);
	x = 0;
	y = 0;
	while (s1 && s1[x])
	{
		dest[x] = (char)s1[x];
		x++;
	}
	while (s2[y] && y < size)
		dest[x++] = (char)s2[y++];
	dest[x] = '\0';
	return (free(s1), dest);
}

size_t	ft_strncpy(char *dest, char *src, size_t size)
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
	return (src_size);
}
