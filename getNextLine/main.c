/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:01:55 by amennad           #+#    #+#             */
/*   Updated: 2023/05/16 16:19:32 by amennad          ###   ########.fr       */
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
	// fd = open("errorfile", O_RDONLY);
	fd = open("twoLineOneWorld", O_RDONLY);
	// fd = open("twoLineMoreWorlds", O_RDONLY);
	// fd = open("lorem", O_RDONLY);
	// fd = open("multispace", O_RDONLY);
	// if (fd == -1)
	// {
	// 	printf("Erreur lors de l'ouverture du fichier.\n");
	// 	return (1);
	// }
	result1 = get_next_line(fd);
	printf("|result1 : %s|\n", result1);
	free(result1);

	result2 = get_next_line(fd);
	printf("|result2 : %s|\n", result2);
	free(result2);
	close(fd);
	fscanf(stdin, "c"); // wait for user to enter input from keyboard
	return (0);
}
