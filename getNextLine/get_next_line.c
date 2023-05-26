/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/26 10:07:58 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *buffer, char *storage)
{
	char	*temp;

	temp = ft_strjoin(storage, buffer);
	free(buffer);
	return (temp);
}

static char	*cut_storage(char *storage)
{
	char	*line;
	char	*temp;
	int		end_line;

	end_line = ft_strchr(storage, '\n');
	line = ft_strdup("");
	free(line);
	line = ft_substr(storage, 0, end_line);
	temp = ft_substr(storage, end_line, ft_strlen(storage));
	free(storage);
	storage = ft_strdup(temp);
	free(temp);
	return (line);
}

static char	*ft_read_file(int fd, char *storage)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nb_read;

	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (NULL);
		else if (nb_read == 0)
			return (storage);
		if (storage)
			storage = ft_join(storage, buffer);
		else
			storage = ft_strdup(buffer);
	}
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	storage = ft_read_file(fd, storage);
	if (!storage)
	{
		free(storage);
		return (NULL);
	}
	line = cut_storage(storage);
	if (!line)
	{
		free(line);
		line = NULL;
		free(storage);
		storage = NULL;
		return (NULL);
	}
	return (line);
}
