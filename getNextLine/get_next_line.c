/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/18 16:51:33 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*check_buffer(int nb_cara_read, char *buffer, char *line, char **temp)
{
	int	i;

	i = 0;
	while (i <= nb_cara_read)
	{
		if (buffer[i] == '\n')
		{
			if (!*temp)
				*temp = malloc(sizeof(char) * (nb_cara_read - i));
			if (!*temp)
			{
				free(line);
				return (NULL);
			}
			*temp = ft_substr(buffer, i, nb_cara_read);
			line = ft_strjoin(line, ft_substr(buffer, 0, i + 1));
			return (line);
		}
		else if (i == nb_cara_read && nb_cara_read < BUFFER_SIZE)
		{
			line = ft_substr(buffer, 0, nb_cara_read);
			return (line);
		}
		i++;
	}
	line = ft_strjoin(line, ft_substr(buffer, 0, nb_cara_read));
	return (NULL);
}

static char	*read_line(int fd, char *buffer, char *line)
{
	int			nb_cara_read;
	static char	*temp;
	if (temp)
	{
		printf(" --temp 2 %s\n", temp);
		line = check_buffer(nb_cara_read, temp, line, &temp);
		if (temp)

		// line = ft_strdup(temp);
		// free(temp);
	}
	nb_cara_read = BUFFER_SIZE;
	while (nb_cara_read > 0 && nb_cara_read)
	{
		nb_cara_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_cara_read <= 0)
		{
			free(line);
			return (NULL);
		}
		printf(" --nb_cara_read : %d\n", nb_cara_read);
		printf(" --line 00 %s\n", line);
		line = check_buffer(nb_cara_read, buffer, line, &temp);
		printf(" --line %s\n", line);
		if (temp)
			return (line);
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
