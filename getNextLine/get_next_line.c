/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/03 14:28:44 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;
	static int	nb_car_lu;

	int line_break ;
	nb_car_lu = BUFFER_SIZE;

	if (fd == -1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (buffer[0])
		line = ft_strdup(buffer);
	else
		line = NULL;
	while (nb_car_lu == BUFFER_SIZE)
	{
		nb_car_lu = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_car_lu] = '\0';
		if (nb_car_lu == -1)
			return (NULL);
		printf("nb_car_lu %d\n", nb_car_lu);
		i = 0;
		line_break = 0;
		while (i < nb_car_lu)
		{
			if (buffer[i] == '\n' || (buffer[i] == '\\' && buffer[i
					+ 1] == 'n'))
			{
				line = ft_strjoin(line, ft_substr(buffer, 0, i));
				buffer = ft_substr(buffer, ++i, nb_car_lu);
				return (line);
			}
			i++;
		}
		if (!line_break)
			printf("no line_break");
		else
			printf("line_break\n");
		printf("BUFFER : %s--\n", buffer);
		if (!line)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, ft_substr(buffer, 0, nb_car_lu));
		printf("LINE : %s--\n", line);
	}
	return (line);
}
