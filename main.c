/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:22:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/18 15:56:26 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	fd;
	char	*line;

//setbuf(stdout, NULL);
	if (ac > 1)
	{
		int x = 1;
		fd = open(av[1], O_RDONLY);
		while (x) {
			//printf("ITERATION NUMBER %i\n", x + 1);
			line = get_next_line(fd);
			if (!line)
				break;
		//	printf("\033[0;36m");
		printf("LINE %s", line);
		//	printf("\033[0m"); // Remet la couleur par défaut
			x++;

			free(line);
		}
		close(fd);
	}
	return (0);
}
