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

static char	*my_strncpy(char *dest, const char *src, unsigned int n)
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

static size_t	my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *str, unsigned int start, size_t lengh)
{
	size_t		lengh_of_str;
	size_t		lengh_of_nstr;
	char		*new_str;

	lengh_of_str = my_strlen(str);
	lengh_of_nstr = lengh_of_str - start;
	if (lengh > lengh_of_nstr)
		lengh = lengh_of_nstr;
	new_str = (char *)malloc(sizeof(char) * (lengh + 1));
	if (new_str == NULL)
		return (NULL);
	my_strncpy(new_str, &str[start], lengh);
	new_str[lengh] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	char const	str[] = "hola";
	char const	*new_str;
//	size_t		lengh = 10;
//	unsigned int	start = 10;

	new_str = ft_substr(str, 4294967295, 0);
	printf("%s\n", new_str);
	free((void *)new_str);
	return (0);
}
*/
