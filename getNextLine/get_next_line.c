/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/25 11:53:56 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *cut_storage(char *storage)
{
	char	*line;
	char	*temp;
	int	end_line;

	end_line = ft_strchr(storage, '\n');




	line = ft_strdup("");
	line = ft_substr(storage, 0, end_line);
	// printf("line : %s\n", line);
	temp = ft_substr(storage, end_line, ft_strlen(storage));
	// printf("temp : %s\n", temp);
	free(storage);
	storage = ft_strdup(temp);
	// // printf("storage : %s\n", storage);
	// printf("storage : %p\n", storage);
	free(temp);
	// // printf("THE LINE : %s\n", line);

	return (line);
}


static char	*ft_read_file(int fd, char *storage)
{
	char	*buffer;
	int		nb_read;

	nb_read = BUFFER_SIZE;
	buffer = malloc(sizeof(char) * BUFFER_SIZE +1);
	if (!buffer)
		return (NULL);
	while (nb_read == BUFFER_SIZE && (ft_strchr(storage, '\n') == -1 ))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (NULL);
		else if (nb_read == 0)
			return (storage);
		if (storage)
		{
			// printf("while storage B: %s\n", storage);
			storage = ft_strjoin(storage, buffer);
			// printf("while storage A: %s\n", storage);
		}
		else
			storage = ft_strdup("titi");
	}
	free(buffer);
	buffer = NULL;
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = malloc(sizeof(char) * BUFFER_SIZE +1);
	if (!storage)
		return (NULL);
	storage = ft_read_file(fd, storage);
	if (storage == 0)
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