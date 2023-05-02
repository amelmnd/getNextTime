/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/02 16:13:53 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	int			i;

	line = NULL;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	printf("1\n");
	while (read(fd, buffer, BUFFER_SIZE) == BUFFER_SIZE)
	{
		printf("2\n");
		printf("line : %s\n", line);
		printf("buffer : %s\n", buffer);
		if (line == NULL)
		{
			printf("3\n");
			line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
			line = ft_substr(buffer, 0, ft_strlen(buffer));
			printf("line1 : %s\n", line);
			printf("4\n");
		}
		else
		{
			printf("5\n");
			i = 0;
			while (i < BUFFER_SIZE)
				i++;
			printf("test\n");
			line = ft_strjoin(line, ft_substr(buffer, 0, i));
			printf("line2 : %s\n", line);
			printf("6\n");
		}
		printf("8\n");
	}
	printf("9\n");
	free(buffer);
	printf("10 : %s\n", line);
	return (line);
}
