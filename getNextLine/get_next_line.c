/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/06/16 16:16:16 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/06/16 13:50:50 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_fd(char *temp, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		nb_read;

	nb_read = 1;
	buffer[0] = '\0';
	while (!ft_strchr(buffer, '\n') && nb_read)
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

char	*gen_line(int fd, char *temp, char **storag)
{
	char *line;

	line = read_fd(temp, fd);
	temp = ft_strdup(line);
	free_elements(&line);
	if (temp && ft_strchr(temp, '\n'))
	{
		line = ft_substr(temp, 0, icis(temp, '\n') + 1);
		if (ft_strlen(line) != ft_strlen(temp))
			*storag = ft_substr(temp, icis(temp, '\n') + 1, ft_strlen(temp));
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
	static char	*storag = NULL;
	char		*line ;
	char		*temp ;

	line = NULL;
	temp = NULL;
	if (!storag)
	{
		return (gen_line(fd, temp, &storag));
	}
	if (ft_strchr(storag, '\n'))
	{
		line = ft_substr(storag, 0, icis(storag, '\n') + 1);
		temp = ft_substr(storag, icis(storag, '\n') + 1, ft_strlen(storag));
		free_elements(&storag);
		storag = ft_strdup(temp);
		free_elements(&temp);
		return (line);
	}
	temp = ft_strdup(storag);
	free_elements(&storag);
	return (gen_line(fd, temp, &storag));
}
