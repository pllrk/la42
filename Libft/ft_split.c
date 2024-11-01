/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:51:38 by plerick           #+#    #+#             */
/*   Updated: 2024/11/01 04:13:39 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	i;

	i = 0;
	while 
}

int	main(void)
{
	char const s[] = "bonjour--je-suis-un-ordinateur";
	char	c = '-';
	char new_str;

	new_str = ft_split(s, c);
	printf("%s\n", new);
	return (0);
}
