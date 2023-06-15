/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/06/15 13:42:11 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_elements(char **str1, char **str2)
{
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
}

void	cut_storage(char **storage, char **line)
{
	int		end_line;
	int		len_line;
	char	*temp;

	end_line = ft_strchr(*storage, '\n');
	len_line = ft_strlen(*storage);
	*line = ft_substr(*storage, 0, end_line);
	temp = ft_strdup(*storage);
	free_elements(storage, 0);
	*storage = ft_substr(temp, end_line, len_line);
	free(temp);
}

void	ft_read_file(int fd, char **storage)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nb_read;

	nb_read = 1;
	while (nb_read && ft_strchr(buffer, '\n') == -1)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1 || (!nb_read && !storage))
			return (free_elements(storage, 0));
		buffer[nb_read] = '\0';
		if (*storage)
			*storage = ft_strjoin(*storage, buffer);
		else
			*storage = ft_strdup(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	ft_read_file(fd, &storage);
	if (!storage || *storage != '\0')
		cut_storage(&storage, &line);
	if (!line || *line == '\0')
		return (free_elements(&storage, &line), NULL);
	return (line);
}
