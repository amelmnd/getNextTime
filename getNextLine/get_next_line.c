/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/18 14:42:19 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// static char	*check_buffer(int nb_cara_read, char *buffer, char *temp,
// 		char *line)
static void	check_buffer(int nb_cara_read, char *buffer)
{
	int	i;
	int	y;
	int	z;

	i = 0;
	y = 0;
	z = 0;
	while (i <= nb_cara_read)
	{
		y++;
		if (buffer[i] == '\n')
		{
			printf("\n- %s\n", ft_substr(buffer, z, y));
			y = 0;
			z = i + 1;
		}
		else if (i == nb_cara_read && nb_cara_read < BUFFER_SIZE)
		{
			printf("\n- %s\n", ft_substr(buffer, 0, nb_cara_read));
		}
		// if (buffer[i] == '\n' && buffer[i + 1] != '\n')
		// {
		// 	temp = malloc(sizeof(char) * (nb_cara_read - i));
		// 	if (!temp)
		// 	{
		// 		free(line);
		// 		return (NULL);
		// 	}
		// 	temp = ft_substr(buffer, i + 1, nb_cara_read);
		// 	line = ft_strjoin(line, ft_substr(buffer, 0, i));
		// 	return (line);
		// }
		i++;
	}
}

static char	*read_line(int fd, char *buffer, char *line)
{
	int			nb_cara_read;
	static char	*temp;

	// printf("-----------TEST 3-----------\n");
	if (temp)
	{
		line = ft_strdup(temp);
		free(temp);
	}
	nb_cara_read = BUFFER_SIZE;
	while (nb_cara_read > 0 && nb_cara_read)
	{
		// printf("-----------TEST 4-----------\n");
		nb_cara_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_cara_read <= 0)
		{
			free(line);
			return (NULL);
		}
		printf(" --nb_cara_read : %d\n", nb_cara_read);
		check_buffer(nb_cara_read, buffer);
		// check_buffer(nb_cara_read, buffer, temp, line);
		line = ft_strjoin(line, ft_substr(buffer, 0, nb_cara_read));
		if (nb_cara_read < BUFFER_SIZE)
			nb_cara_read = 0;
	}
	// printf("-----------TEST 6-----------\n");
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
	// printf("-----------TEST 7-----------\n");
	line = read_line(fd, buffer, line);
	// printf("-----------TEST 8-----------\n");
	free(buffer);
	return (line);
}
