/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:22:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/21 20:04:32 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		x;

	if (ac > 1)
	{
		x = 1;
		fd = open(av[1], O_RDONLY);
		while (x)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
			printf("\033[0;32m");
			printf("LINE %s", line);
			printf("\033[0m");
			free(line);
		}
		close(fd);
	}
	return (0);
}
