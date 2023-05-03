/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/05/03 11:21:41 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	static char		*buffer;
	char		*line;
	size_t		i;
	static int nb_car_lu = BUFFER_SIZE;

	line = NULL;
	if (fd == -1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while (nb_car_lu == BUFFER_SIZE)
	{
		nb_car_lu = read(fd, buffer, BUFFER_SIZE);
		printf("nb_car_lu %d\n", nb_car_lu);
		i = 0;
		// while ((buffer[i] != '\n') && (i < ft_strlen(buffer)))
		while (buffer[i] != '\0')
		{
			if (buffer[i] == 'o')
				return (line);
			printf("i = buffer[i] : %zu = %c\n", i, buffer[i]);
			i++;
		}
		printf("BUFFER : %s--\n", buffer);
		// if (i == ft_strlen(buffer))
		// 	printf("SEMME\n");
		// else
		// 	printf("DIFF\n");
		// printf("BUFFER : %c--\n", buffer[i]);
		if (!line)
			line = ft_strdup(buffer);
		else
			line = ft_strjoin(line, ft_substr(buffer, 0, ft_strlen(buffer)));
		printf("LINE : %s--\n", line);
	}
	// free(buffer);
	// buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (read(fd, buffer, BUFFER_SIZE) < BUFFER_SIZE)
	{
	// 	printf("read(fd, buffer, BUFFER_SIZE) %zd\n", read(fd, buffer, BUFFER_SIZE) );
	// 	printf("strlen buffer = %zu\n", ft_strlen(buffer));
		printf("end buffer = %s\n", buffer);
	line = ft_strjoin(line, ft_substr(buffer, 0, ft_strlen(buffer)));


	}
	if (read(fd, buffer, BUFFER_SIZE) == -1)
		return (NULL);
	return (line);
}
