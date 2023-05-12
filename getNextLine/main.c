/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:01:55 by amennad           #+#    #+#             */
/*   Updated: 2023/05/12 16:06:55 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*result1;
	char	*result2;

	// fd = open("oneLineOneWorld", O_RDONLY);
	// fd = open("oneLineMoreWorlds", O_RDONLY);
	fd = open("oneLMoreWorlds", O_RDONLY); //-1
	// fd = open("oneLMoreWorldsn", O_RDONLY);
	// fd = open("lorem", O_RDONLY);
	// fd = open("multispace", O_RDONLY);

	result1 = get_next_line(fd);
	printf("|result1 : %s|\n", result1);
	free(result1);
	result2 = get_next_line(fd);
	printf("|result2 : %s|\n", result2);
	free(result2);
	// while(1)
	// ;
	return (0);
}
