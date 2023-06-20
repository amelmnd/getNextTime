/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:14:57 by amennad           #+#    #+#             */
/*   Updated: 2023/06/20 10:43:31 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	free_elements(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*read_fd(char *temp, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nb_read;

	nb_read = 1;
	buffer[0] = '\0';
	while (nb_read && line_chr(buffer) == -1)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1 || (!nb_read && !temp))
		{
			free_elements(&temp);
			return (0);
		}
		buffer[nb_read] = '\0';
		if (temp)
			temp = ft_strjoin(temp, buffer);
		else
			temp = ft_strdup(buffer);
	}
	return (temp);
}

char	*gen_line(int fd, char *temp, char **storage)
{
	char	*line;

	line = read_fd(temp, fd);
	temp = ft_strdup(line);
	free_elements(&line);
	if (temp && (line_chr(temp) != -1))
	{
		line = ft_substr(temp, 0, line_chr(temp) + 1);
		if (ft_strlen(line) != ft_strlen(temp))
			*storage = ft_substr(temp, line_chr(temp) + 1, ft_strlen(temp));
		free_elements(&temp);
		return (line);
	}
	if (temp)
		return (temp);
	free_elements(&temp);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*line ;
	char		*temp ;
	int			len_storage;

	line = NULL;
	temp = NULL;
	if (!storage[fd])
	{
		return (gen_line(fd, temp, &storage[fd]));
	}
	if (line_chr(storage[fd]) != -1)
	{
		len_storage = ft_strlen(storage[fd]);
		line = ft_substr(storage[fd], 0, line_chr(storage[fd]) + 1);
		temp = ft_substr(storage[fd], line_chr(storage[fd]) + 1, len_storage);
		free_elements(&storage[fd]);
		storage[fd] = ft_strdup(temp);
		free_elements(&temp);
		return (line);
	}
	temp = ft_strdup(storage[fd]);
	free_elements(&storage[fd]);
	return (gen_line(fd, temp, &storage[fd]));
}
