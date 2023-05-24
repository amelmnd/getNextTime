/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/24 13:48:43 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	end_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
static char *cut_line(char *storage, char *line)
{

}

static char *ft_read_file(int fd, char *storage)
{
	char	*buffer;
	int		nb_read;

	nb_read = BUFFER_SIZE;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (nb_read > 0 && (end_line(buffer) == -1)) //✅
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (storage)
			storage = ft_strjoin(storage, buffer);
		else
			storage = ft_strdup(buffer);
	}
	free(buffer); //✅
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read_file(fd, storage);
	return (storage);
}
