/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:01:55 by amennad           #+#    #+#             */
/*   Updated: 2023/05/26 09:59:02 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <fcntl.h>
#include "sys/time.h"

int main(int c, char **b)
// int main()
{
	int		fd;
	char	*result;
	if (c != 2)
		return (0);

	// fd = open("oneLineOneWorld", O_RDONLY);
	// fd = open("oneLineMoreWorlds", O_RDONLY);
	// fd = open("errorfile", O_RDONLY);
	// fd = open(b[1], O_RDONLY);
	// fd = open("twoLineMoreWorlds", O_RDONLY);
	// fd = open("lorem", O_RDONLY);
	// fd = open("multispace", O_RDONLY);
	fd = open(b[1], O_RDONLY);
	result = get_next_line(fd);


		printf("result : %s\n", result) ;
		result = get_next_line(fd);
		// usleep(100000);
	
	free(result);
	system("leaks a.out");

	//	fscanf(stdin, "c"); // wait for user to enter input from keyboard

	return (0);
}
