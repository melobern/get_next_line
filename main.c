/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:22:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/22 14:12:15 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	one_fd_test(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("\033[0;32m");
		printf("LINE %s", line);
		printf("\033[0m");
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	close(fd);
}

void	two_fd_test(int ac, char **av)
{
	int		fd;
	int		fd_two;
	char	*line;

	fd = open(av[1], O_RDONLY);
	fd_two = open(av[2], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("\033[0;32m");
		printf("LINE %s", line);
		printf("\033[0m");
		free(line);
		line = get_next_line(fd_two);
		if (!line)
			break ;
		printf("\033[0;36m");
		printf("LINE %s", line);
		printf("\033[0m");
		free(line);
	}
	close(fd);
	close(fd_two);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		one_fd_test(ac, av);
	else if (ac > 2)
		two_fd_test(ac, av);
	return (0);
}
