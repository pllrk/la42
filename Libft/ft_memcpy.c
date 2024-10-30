/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:34:39 by plerick           #+#    #+#             */
/*   Updated: 2024/10/23 21:45:51 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
/*
	char	dest[] = "Hello_world";
	char	*src = &dest[5];	

	char	dest2[] = "Hello_world";
	char	*src2 = &dest2[5];

	size_t	n = 6;

	char	src[] = "0123456789";
	char	*dest = &src[4];

	char	src2[] = "0123456789";
	char	*dest2 = &src2[4];

	size_t	n = 6;

	printf("%s\n", (char *)ft_memcpy(dest, src, n));
	printf("%s\n", (char *)memcpy(dest2, src2, n));
	return (0);

}
*/
