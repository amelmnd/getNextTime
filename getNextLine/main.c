/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:01:55 by amennad           #+#    #+#             */
/*   Updated: 2023/05/30 10:07:59 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "sys/time.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		fd;
	char	*result;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	result = NULL;
	for (int i = 0; i < 10; i++)
	{
		result = get_next_line(fd);
		printf("result : %s\n", result);
		free(result);
		result = NULL;
	}
	// system("leaks a.out");
	return (0);
}
