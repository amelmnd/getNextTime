/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/04/25 15:07:27 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int		buffer_size;
	int		retrieve;
	char	*buffer;
	char	*temp;
	int 	i;

	buffer_size = 2;
	temp = (char *)malloc(sizeof(char) * buffer_size);
	buffer = (char *)malloc(sizeof(char) * (buffer_size * i));
	while ((retrieve = read(fd, buffer, buffer_size)) == buffer_size)
	{
		free(buffer);
		printf("retrieve : %d\n", retrieve);
		printf("buffer : %s\n", buffer);
		printf("i : %d\n", i);
		i++;
	}
	return (buffer);
}
