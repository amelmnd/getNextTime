/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:01:55 by amennad           #+#    #+#             */
/*   Updated: 2023/05/02 15:34:41 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*result1;
	char	*result2;

	fd = open("oneLineOneWorld", O_RDONLY);
	// fd = open("oneLineMoreWorlds", O_RDONLY);
	// fd = open("lorem", O_RDONLY);
	// fd = open("oneLineMoreWorlds\\n", O_RDONLY);
	if (fd == -1)
		printf("open() failed\n");
	result1 = get_next_line(fd);
	result2 = get_next_line(fd);
		printf("result1 : -------------|%s|-------------", result1);
		printf("result2 :%s", result2);
	return (0);
}
