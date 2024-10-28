/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:16:26 by plerick           #+#    #+#             */
/*   Updated: 2024/10/28 19:32:09 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (c == '\0' && str[i] == '\0')
		return (&(((char *)str)[i]));
	while (i >= 0)
	{
		if (c == str[i])
			return (&(((char *)str)[i]));
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "qwetr";
	int	c = 'w';
	const char	str2[] = "qwetr";
	int	c2 = 'w';


	printf("%s\n", ft_strrchr(str, c));
	printf("%s\n", strrchr(str2, c2));
	return (0);
}
*/
