/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:01 by amennad           #+#    #+#             */
/*   Updated: 2023/04/28 12:03:44 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *) malloc(sizeof(char) *(ft_strlen(s1)) + 1);
	if (!copy)
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		result = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*result;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[y] != '\0')
	{
		result[i + y] = s2[y];
		y++;
	}
	result[i + y] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*line;
	int			buffer_size;
	char		*buffer;
	int			i;

	buffer_size = 2;
	buffer = (char *)malloc(sizeof(char) * buffer_size);
	printf("fd gnl file : %d\n", fd);
	while (read(fd, buffer, buffer_size) != 0)
	{
		printf("buffer : %s\n", buffer);
		if (!line)
		{
			line = (char *)malloc(sizeof(char) * buffer_size);
			line = buffer;
		}
		else
		{
			while (buffer[i] != '\n')
			{
				i++;
			}
			// line = ft_strjoin(line, buffer);
			line = ft_strjoin(line, ft_substr(buffer, 0, i));
		}
		// printf("line : %s\n", line);
	}
	printf("line : %s\n", line);
	return (line);
}
