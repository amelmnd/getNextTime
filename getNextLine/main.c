/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:01:55 by amennad           #+#    #+#             */
/*   Updated: 2023/05/25 12:03:03 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <fcntl.h>
#include "sys/time.h"

// int main(int fd, char **b)
int main()
{
	int		fd;
	char	*result;

	// fd = open("oneLineOneWorld", O_RDONLY);
	// fd = open("oneLineMoreWorlds", O_RDONLY);
	// fd = open("errorfile", O_RDONLY);
	// fd = open(b[1], O_RDONLY);
	// fd = open("twoLineMoreWorlds", O_RDONLY);
	// fd = open("lorem", O_RDONLY);
	// fd = open("multispace", O_RDONLY);
	fd = open("little", O_RDONLY);
	result = get_next_line(fd);
	while (result[0])
	{

		printf("result1 : %s\n", result) ;
		result = get_next_line(fd);
		// usleep(100000);
	}
	free(result);
	system("leaks exec");

	//	fscanf(stdin, "c"); // wait for user to enter input from keyboard

	return (0);
}
