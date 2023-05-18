/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/18 11:04:20 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer, char *line)
{
	int			nb_cara_read;
	int			i;
	static char	*temp;

	if (temp)
	{
		line = ft_strdup(temp);
		free(temp);
	}
	nb_cara_read = BUFFER_SIZE;
	while (nb_cara_read > 0)
	{
		i = 0;
		nb_cara_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_cara_read <= 0)
		{
			free(line);
			return (NULL);
		}
		while (i < nb_cara_read)
		{
			if (buffer[i] == '\n')
			{
				temp = malloc(sizeof(char) * (nb_cara_read - i));
				if (!temp)
				{
					free(line);
					return (NULL);
				}
				temp = ft_substr(buffer, i + 1, nb_cara_read);
				line = ft_strjoin(line, ft_substr(buffer, 0, i));
				return (line);
			}
			i++;
		}
		line = ft_strjoin(line, ft_substr(buffer, 0, nb_cara_read));
		if (nb_cara_read < BUFFER_SIZE)
			nb_cara_read = 0;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	if (fd == -1)
		return (NULL);
	buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	line = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	line = read_line(fd, buffer, line);
	free(buffer);
	return (line);
}
