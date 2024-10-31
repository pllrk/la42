/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:19:53 by plerick           #+#    #+#             */
/*   Updated: 2024/10/29 21:49:30 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

static char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(const char *str, int start, int lengh)
{
	int	lengh_of_str;
	int	lengh_of_nstr;
	char	*new_str;

	lengh_of_str = ft_strlen(str);
	if (start > lengh_of_str || start < 0 || lengh < 0)
		return (NULL);
	lengh_of_nstr = lengh_of_str - start;
	if (lengh > lengh_of_nstr)
		lengh = lengh_of_nstr;
	new_str = (char *)malloc(sizeof(char) * (lengh + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, &str[start], lengh);
	new_str[lengh] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	const char	str[] = "1234567890";
	const char	*new_str;
	int	lengh = 4;
	int	start = 0;

	new_str = ft_substr(str, start, lengh);
	printf("%s\n", new_str);
	free((void *)new_str);
	return (0);
}
*/
