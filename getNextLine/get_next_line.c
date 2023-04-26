/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/04/26 13:31:34 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	int			buffer_size;
	char		*buffer;
	static char	*

	buffer_size = 2;
	buffer = (char *)malloc(sizeof(char) * buffer_size);
	printf("fd gnl file : %d\n", fd);
	read(fd, buffer, buffer_size);
	return (buffer);
}
