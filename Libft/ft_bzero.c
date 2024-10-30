/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:16:46 by plerick           #+#    #+#             */
/*   Updated: 2024/10/29 20:17:15 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>
//#include <stdio.h>
//#include <string.h>

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "hahohi";
	size_t	n = 2;
	char	str2[] = "hahohi";

	ft_bzero(str, n);
	bzero(str2, n);

	printf("%s\n", str);
	printf("%s\n", str2);
	return (0);
}
*/
