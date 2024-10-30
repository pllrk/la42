/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:22:13 by plerick           #+#    #+#             */
/*   Updated: 2024/10/30 02:38:30 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while(s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	count;

	count = 0;
	while (dest[count] != '\0')
		count++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[i + count] = src[i];
		i++;
	}
	dest[i + count] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	int	i;
	size_t	total_lengh;
	char	*new_str;

	i = 0;
	total_lengh = ft_strlen(str1) + ft_strlen(str2);
	new_str = (char *)malloc(sizeof(char) * total_lengh + 1);
	if (new_str == NULL)
		return (NULL);
	new_str = ft_strcat(new_str, str1);
	new_str = ft_strcat(new_str, str2);
	return (new_str);
}
/*
int	main(void)
{
	char const	str1[] = "un";
	char const	str2[] = "deux";
	char	*result;

	result = ft_strjoin(str1, str2);
	printf("%s\n", result);
	free(result);
	return (0);
}
*/
