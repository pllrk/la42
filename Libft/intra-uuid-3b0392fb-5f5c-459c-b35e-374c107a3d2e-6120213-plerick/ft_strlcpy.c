/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:56:59 by plerick           #+#    #+#             */
/*   Updated: 2024/10/27 20:39:43 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>
//#include <stdio.h>
//#include <string.h>

/*
size_t	strlcpy(char *dst, const char *src, size_t dsize)
{
	const char *osrc = src;
	size_t nleft = dsize;

//	 Copy as many bytes as will fit.
	if (nleft != 0) {
		while (--nleft != 0) {
			if ((*dst++ = *src++) == '\0')
				break;
		}
	}

//	Not enough room in dst, add NUL and traverse rest of src.
	if (nleft == 0) {
		if (dsize != 0)
			*dst = '\0';		
						//NUL-terminate dst
		while (*src++);
	}
	return(src - osrc - 1);	
	//count does not include NUL
}
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = 0;
	i = 0;
	while (src[len_src] != '\0')
		len_src++;
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
	const char	src1[] = "hahohi";
	const char	src2[] = "hahohi";
	char	dest1[10];
	char	dest2[10];
	size_t	size1 = strlen(src1);
	size_t	size2 = strlen(src2);

	size_t result1 = ft_strlcpy(dest1, src1, size1 + 1);
	size_t result2 = strlcpy(dest2, src2, size2 + 1);

	printf("Copied string: '%s'\n", dest1);
	printf("Length of source string: %zu\n", result1);
	printf("Copied string: '%s'\n", dest2);
	printf("Length of source string: %zu\n", result2);
	return (0);
}
*/
