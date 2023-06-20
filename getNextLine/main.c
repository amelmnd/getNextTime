/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:01:55 by amennad           #+#    #+#             */
/*   Updated: 2023/06/20 09:46:31 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "sys/time.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*result;
	int		i;

	i = 0;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	result = NULL;
	while (i < 10)
	{
		result = get_next_line(fd);
		printf("result : %s\n", result);
		free(result);
		result = NULL;
		i++;
	}
	// close(fd);
	// fd = open(av[1], O_RDONLY);
	// i = 0;
	// while (i < 6)
	// {
	// 	result = get_next_line(fd);
	// 	printf("r after close: %s\n", result);
	// 	free(result);
	// 	result = NULL;
	// 	i++;
	// }
	system("leaks a.out");
	return (0);
}
