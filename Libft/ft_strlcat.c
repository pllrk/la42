/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:00:56 by plerick           #+#    #+#             */
/*   Updated: 2024/10/28 01:20:14 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;
	size_t	n;

	len_src = 0;
	len_dest = 0;
	i = 0;
	n = 0;
	while (src[len_src] != '\0')
		len_src++;
	while (dest[len_dest] != '\0' && len_dest < size)
		len_dest++;
	if (len_dest >= size)
		return (len_dest + len_src);
	n = len_dest;
	while (i < size - len_dest - 1 && src[i] != '\0')
	{
		dest[n] = src[i];
		i++;
		n++;
	}
	dest[n] = '\0';
	return (len_dest + len_src);
}
/*
int	main(void)
{
	const char	src1[] = "0123456789";
	char	dest1[20] = "abcdefgh";
	size_t	size1 = 18;

	size_t result1 = ft_strlcat(dest1, src1, size1 + 1);

	printf("Copied string: '%s'\n", dest1);
	printf("Length of source string: %zu\n", result1);
	return (0);
}
*/
