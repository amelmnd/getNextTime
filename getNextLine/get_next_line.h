/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amennad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:13:05 by amennad           #+#    #+#             */
/*   Updated: 2023/06/16 16:18:20 by amennad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // DELETE

char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		ft_strchr(char *s, char c);
int		icis(char *s, char c);
void	free_elements(char **dust);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);


#endif
