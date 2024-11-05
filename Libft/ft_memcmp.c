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

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	int		diff;

	if (n == '0')
		return (0);
	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)str1)[i]) != (((unsigned char *)str2)[i]))
			return (diff = (((unsigned char *)str1)[i])
				- (((unsigned char *)str2)[i]));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[] = "abcdef";
	char	str2[] = "abc\375xx";
	size_t	n = 5;
	
	char	str3[] = "abcdef";
	char	str4[] = "abc\375xx";
	printf("%d\n", ft_memcmp(str1, str2, n));
	printf("%d\n", memcmp(str3, str4, n));
	return (0);
}
*/
