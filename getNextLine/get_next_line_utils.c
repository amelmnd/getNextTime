/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:12:55 by amennad           #+#    #+#             */
/*   Updated: 2023/06/16 16:23:07 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int ft_strlen(char *s)
{
	int i = -1;
	while(s[++i]);
	return (i);
}

int ft_strchr(char *s, char c)
{
	int i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (1);
	}
	return (0);
}

int icis(char *s, char c)
{
	int i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (i);
	}
	return (0);
}
void free_elements(char **dust)
{
	if (*dust)
	{
		free(*dust);
		*dust = NULL;
	}
}
char *ft_strdup(char *s)
{
	char *dup = NULL;
	int i = -1;
	if (!s)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *join = NULL;
	int i = -1;
	int j = -1;
	int lens1 = ft_strlen(s1);
	int lens2 = ft_strlen(s2);

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!join)
		return (NULL);
	while (++i < lens1)
		join[i] = s1[i];
	while (++j < lens2)
		join[i + j] = s2[j];
	join[i + j] = '\0';
	if (s1)
		free(s1);
	return (join);
}

char	*ft_substr(char *s, int start, int len)
{
	char *sub = NULL;
	int i = -1;
	int slen = ft_strlen(s);

	if (!s || start >= slen)
		return (NULL);
	if (slen - start > len)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	else
		sub = (char *)malloc(sizeof(char) * (slen - start + 1));
	if (!sub)
		return (NULL);
	while (++i < len && s[start])
	{
		sub[i] = s[start];
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
