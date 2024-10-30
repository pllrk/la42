/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:32:39 by plerick           #+#    #+#             */
/*   Updated: 2024/10/25 18:41:00 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	int		diff;

	if (n == '0')
		return (0);
	i = 0;
	while (i < n)
	{
		if ((((char *)str1)[i]) != (((char *)str2)[i]))
			return (diff = (((char *)str1)[i]) - (((char *)str2)[i]));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "abc";
	char	str2[] = "abc";
	size_t	n = -1;
	
	char	str3[] = "abc";
	char	str4[] = "abc";
	printf("%d\n", ft_memcmp(str1, str2, n));
	printf("%d\n", memcmp(str3, str4, n));
	return (0);
}
*/
