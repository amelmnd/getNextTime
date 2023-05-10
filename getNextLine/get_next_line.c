/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/10 10:51:05 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_line(fd)
{
	char	*buffer;
	char	*line;
	int		read_nb_cara;

	// printf("fd : %d\n", fd);
	buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	// printf("buffer : %p\n", buffer);

	line = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	// read_nb_cara = read(fd, buffer, BUFFER_SIZE);
	while ((read_nb_cara = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		// printf("read_nb_cara : %d\n", read_nb_cara);
		// printf("buffer : %s\n", buffer);
		line = ft_strjoin(line, buffer);
		// printf("line : %s\n", line);
	}
	free(buffer);
	// printf("read_nb_cara : %d\n", read_nb_cara);
	return (line);
}

char	*get_next_line(int fd)
{
	// char	*buffer;
	// char	*line;



	// int		read_nb_cara;

	// // printf("fd : %d\n", fd);
	// buffer = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	// // printf("buffer : %p\n", buffer);

	// line = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	// // read_nb_cara = read(fd, buffer, BUFFER_SIZE);
	// while ((read_nb_cara = read(fd, buffer, BUFFER_SIZE)) != 0)
	// {
	// 	// printf("read_nb_cara : %d\n", read_nb_cara);
	// 	// printf("buffer : %s\n", buffer);
	// 	line = ft_strjoin(line, buffer);
	// 	// printf("line : %s\n", line);
	// }
	// free(buffer);
	// // printf("read_nb_cara : %d\n", read_nb_cara);
	return (read_line(fd));
}
