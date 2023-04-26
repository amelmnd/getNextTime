/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:01:55 by amennad           #+#    #+#             */
/*   Updated: 2023/04/26 13:19:47 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*result;

	fd = open("oneLineOneWorld", O_RDONLY);
	// fd = open("oneLineMoreWorlds", O_RDONLY);
	// fd = open("lorem", O_RDONLY);
	if (fd == -1)
		printf("open() failed\n");
	printf("fd main file : %d\n", fd);
	result = get_next_line(fd);
	printf("%s\n", result);
	return (0);
}
