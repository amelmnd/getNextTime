/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/12 16:05:46 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*read_line(fd)
{
	char	*buffer;
	char	*line;
	int		nb_cara_read;
	// char	*temp;

	nb_cara_read = BUFFER_SIZE;
	buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buffer)
		return (NULL);
	line = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!line)
		return (NULL);
	while (nb_cara_read > 0)
	{

		nb_cara_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_cara_read == -1)
			return (NULL);

		line = ft_strjoin(line, ft_substr(buffer, 0, nb_cara_read));

	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	if (fd == -1)
		return (NULL);
	return (read_line(fd));
}
