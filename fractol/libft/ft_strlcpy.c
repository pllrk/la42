/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:56:59 by plerick           #+#    #+#             */
/*   Updated: 2025/04/03 22:15:58 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = 0;
	i = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size == 0)
		return (len_src);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len_src);
}
/*
int	main(void)
{
	const char	src1[] = "0122333444455555666666777777788888888999999999";
	char	dest1[5];
	size_t	size1 = (src1);
	size_t result1 = ft_strlcpy(dest1, src1, size1);

	printf("Copied string: '%s'\n", dest1);
	printf("Length of source string: %zu\n", result1);
	return (0);
}
*/
