/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:33:29 by plerick           #+#    #+#             */
/*   Updated: 2024/10/28 20:22:50 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (str1[i] == '\0' || str2[i] == '\0')
			return (str1[i] - str2[i]);
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char	str1[] = "d";
	const char	str2[] = "dbcdd";
	size_t	n = 10;

	printf("%d\n", ft_strncmp(str1, str2, n));
	printf("%d\n", strncmp(str1, str2, n));
	return (0);
}
*/
