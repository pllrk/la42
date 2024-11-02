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

//#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 1;
	i = 0;
	if (s[i] == c)
		count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] != c && s[i] != '\0')
				count++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_word;

	if (*s == '\0' || c == '\0')
		return (NULL);
	nb_words = (ft_count(s, c));
	return (0);
}

int	main(void)
{
	char const s[] = "-------Bonjour-je-suis-un-pc----";
	char	c = '-';
	char new_str;

//	printf("%d\n", ft_count(s, c));
	new_str = ft_split(s, c);
	printf("%s\n", new_str);
	return (0);
}
