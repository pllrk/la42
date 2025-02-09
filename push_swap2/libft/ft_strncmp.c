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

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	s1;
	unsigned char	s2;

	i = 0;
	while (i < n)
	{
		s1 = (unsigned char)str1[i];
		s2 = (unsigned char)str2[i];
		if (s1 == '\0' || s2 == '\0')
			return (s1 - s2);
		if (s1 != s2)
			return (s1 - s2);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "test\200";
	char	str2[] = "test\0";
	size_t	n = 6;

	printf("%d\n", ft_strncmp(str1, str2, n));
	printf("%d\n", strncmp(str1, str2, n));
	return (0);
}
*/
