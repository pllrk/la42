/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:48:08 by plerick           #+#    #+#             */
/*   Updated: 2024/10/25 17:30:17 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	uc;

	i = 0;
	string = (unsigned char *)str;
	uc = (unsigned char) c;
	while (i < n)
	{
		if (string[i] == uc)
			return (&string[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	str[] = "0123456qhohohoho";
	char	c = '\0';
	size_t n = 7;

	const char	str2[] = "0123456qhohohoho";
	char	c2 = '\0';
	size_t n2 = 7;
	

	printf("%s\n", (char *)ft_memchr(str, c, n));
	printf("%s\n", (char *)memchr(str2, c2, n2));
	return (0);
}
*/
