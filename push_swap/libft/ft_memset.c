/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:55:35 by plerick           #+#    #+#             */
/*   Updated: 2024/10/22 19:30:16 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int to_include, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = to_include;
		i++;
	}
	return ((char *)str);
}
/*
int	main(void)
{
	char	str[] = "c'est un test";
	char	to_include = 'q';
	int	n = 5;

	printf("la phrase est %s\n",(char *)ft_memset(str, to_include, n));
	printf("la phrase est %s",(char *)memset(str, to_include, n));
	return (0);	
}
*/
