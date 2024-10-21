/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:15:07 by plerick           #+#    #+#             */
/*   Updated: 2024/10/21 21:00:02 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <bsd/string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	temp;

	i = 0;
	temp = 0;
	if (to_find[i] == '\0')
		return ((char *) str);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == to_find[0])
		{
			while (str[temp + i] == to_find[temp] && i + temp < len)
			{
				temp++;
				if (to_find[temp] == '\0')
					return ((char *) &str[i]);
			}
			temp = 0;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	la_phrase[] = "toto est rigolo";
	const char	motyes[] = "";
	size_t	len = 8;

	printf("le mot a ete trouve : %s \n", ft_strnstr(la_phrase, motyes, len));
	printf("le mot a ete trouve : %s", strnstr(la_phrase, motyes, len));
	return (0);
}
*/
