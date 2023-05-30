/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/30 10:53:20 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_elements(char **str1, char **str2, char **str3)
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
	if (str3 && *str3)
	{
		free(*str3);
		*str3 = NULL;
	}
}

void	cut_storage(char **storage, char **backup, char **line)
{
	int	end_line;

	end_line = ft_strchr(*storage, '\n');
	*line = ft_substr(*storage, 0, end_line);
	*backup = ft_strdup(*storage);
	free_elements(storage, 0, 0);
	*storage = ft_substr(*backup, end_line, ft_strlen(*backup + end_line));
	free(*backup);
}

void	ft_read_file(int fd, char **storage, char **backup)
{
	char	*buffer;
	int		nb_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return ;
	nb_read = 1;
	while (nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (free_elements(storage, backup, &buffer));
		buffer[nb_read] = '\0';
		*backup = ft_strdup(*storage);
		free_elements(storage, 0, 0);
		*storage = ft_strjoin(*backup, buffer);
		free_elements(backup, 0, 0);
		if (ft_strchr(*storage, '\n') != -1)
			break ;
		if (ft_strchr(*storage, '\0') != -1)
			break ;
	}
	free_elements(&buffer, 0, 0);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		*backup;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0 , 0) < 0)
		return (NULL);
	line = NULL;
	backup = NULL;
	ft_read_file(fd, &storage, &backup);
	if (!storage || *storage != '\0')
		cut_storage(&storage, &backup, &line);
	if (!line || *line == '\0')
		return (free_elements(&storage, &backup, &line), NULL);
	return (line);
}

