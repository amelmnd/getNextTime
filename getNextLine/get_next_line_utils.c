/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:12:55 by amennad           #+#    #+#             */
/*   Updated: 2023/05/16 15:40:12 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1)) + 1);
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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*result;

	i = 0;
	s_len = ft_strlen(s);
	if (!s)
		return (ft_strdup(""));
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len)
		result = (char *)malloc(sizeof(char) * (s_len + 1));
	else
		result = (char *)malloc(sizeof(char) * (len + 1));
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		y;
	char	*result;

	i = 0;
	y = 0;
	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
	free(s1);
	free(s2);
	return (result);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	*element;
	size_t	i;
	size_t	total_size;

	total_size = count * size;
	if (size == SIZE_MAX || total_size > SIZE_MAX)
		count = 1;
	element = (void *) malloc(total_size);
	if (!element)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *) element)[i] = (unsigned char) 0;
		i++;
	}
	return ((void *) element);
}
