/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/05 10:46:27 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;
	int			read_nb_cara;
	int			line_break;

	read_nb_cara = BUFFER_SIZE;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("____BUFFER : %s____", buffer);
	if (buffer)
		line = ft_strdup(buffer);
	else
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		line = NULL;
	}
	printf("____LINE : %s____", line);

	while (read_nb_cara == BUFFER_SIZE)
	{
		read_nb_cara = read(fd, buffer, BUFFER_SIZE);
		printf("buffer 1 : %s\n", buffer);
		buffer[read_nb_cara] = '\0';
		if (read_nb_cara == -1)
			return (NULL);
		i = 0;
		line_break = 0;
		while (i < read_nb_cara)
		{
			if (buffer[i] == '\n')
			{
				line = ft_strjoin(line, ft_substr(buffer, 0, i));
				printf("---- line : %s------\n", line);
				buffer = ft_substr(buffer, ++i, read_nb_cara);
				printf("---- BUFFER : %s------\n", buffer);
				return (line);
			}
			i++;
		}
		printf("BUFFER : %s--\n", buffer);
		if (!line)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, ft_substr(buffer, 0, read_nb_cara));
		printf("LINE : %s--\n", line);
	}
	return (line);
}
