/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:18:13 by plerick           #+#    #+#             */
/*   Updated: 2024/11/21 01:18:17 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strchr(const char *str, int c);
void	*my_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t num, size_t size);
size_t	my_strlen(const char *s);
char	*ft_strjoin(char *str1, char *str2);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer);
char	*ft_free(int fd, char *buffer, char *tojoin, int *count);
char	*ft_avant_next_line(char *buffer);
char	*ft_apres_next_line(char *buffer);

#endif