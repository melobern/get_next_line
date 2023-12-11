/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:22:35 by mbernard          #+#    #+#             */
/*   Updated: 2023/12/11 17:32:29 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int fd = open(av[1], O_RDONLY);
	
		printf("\n%s", get_next_line(fd));
	}
	return (0);
}
