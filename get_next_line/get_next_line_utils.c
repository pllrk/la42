/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:17:51 by plerick           #+#    #+#             */
/*   Updated: 2024/11/21 01:17:53 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	vc;

	i = 0;
	vc = (unsigned char) c;
	while (str[i] != '\0')
	{
		if (vc == str[i])
			return (&(((char *)str)[i]));
		i++;
	}
	if (vc == '\0' && str[i] == '\0')
		return (&(((char *)str)[i]));
	return (NULL);
}

void	*my_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	my_memset((int *)ptr, 0, (num * size));
	return (ptr);
}

size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		total_lengh;
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	total_lengh = my_strlen(str1) + my_strlen(str2);
	new_str = (char *)malloc(sizeof(char) * (total_lengh + 1));
	if (new_str == NULL || str1 == NULL || str2 == NULL)
		return (NULL);
	while (str1[i] != 0)
	{
		new_str[i] = str1[i];
		i++;
	}
	while (str2[j] != 0)
		new_str[i++] = str2[j++];
	new_str[total_lengh] = 0;
	return (new_str);
}
