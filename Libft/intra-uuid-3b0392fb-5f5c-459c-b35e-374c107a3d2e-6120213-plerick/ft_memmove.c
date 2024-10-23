/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:37:27 by plerick           #+#    #+#             */
/*   Updated: 2024/10/23 19:30:00 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL || src == NULL)
		return (0);
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}	
	return ((char *)dest);
}
/*
// dest < src

int main()
{
	char dest[] = "Hello_world";
	char *src = &dest[4];
	char *stock1 = (char *)ft_memmove(dest, src, 3);


	char dest2[] = "Hello_world";
	char *src2 = &dest2[4];
	char *stock2 = (char *)ft_memmove(dest2, src2, 3);

	printf("%s\n", stock1);
	printf("%s\n", stock2);
	return (0);
}

// dest > src

int main()
{
	char src[] = "Hello_world";
	char *dest = &src[2];
	char *stock1 = (char *)ft_memmove(dest, src, 6);

	char src2[] = "Hello_world";
	char *dest2 = &src2[2];
	char *stock2 = (char *)memmove(dest2, src2, 6);

	printf("%s\n", stock1);
	printf("%s\n", stock2);
	return (0);
}
*/
