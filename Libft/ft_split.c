/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:51:38 by plerick           #+#    #+#             */
/*   Updated: 2024/11/02 22:22:29 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static	char	*ft_strcpy(char *tabg, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c || *s == s[0])
	{
		i++;
		s--;
	}
	if (*s == s[0])
	{
		i++;
		while (i-- > 0)
			*tabg++ = *s++;
	}
	else
	{
		s++;
		while (i-- > 0)
			*tabg++ = *s++;
	}
	*tabg = '\0';
	return (tabg);
}

static size_t	ft_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c || *s == s[0])
	{
		i++;
		s--;
	}
	if (*s == s[0])
		i++;
	return (i);
}

static int	ft_count(char const *s, char c)
{
	int	count;
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
	char	**tabg;
	int	i;

	i = 0;
	if (*s == '\0' || c == '\0')
		return (NULL);
	nb_word = (ft_count(s, c));
	tabg = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (tabg == NULL)
		return (NULL);
	while (*s)
	{
		if ((*s != c) && ((*s + 1) == (int)c || (*s + 1) == '\0'))
		{
			tabg[i] = (char *)malloc(sizeof(char) * ft_word(s, c) + 1);
			if (tabg[i] == NULL)
				{
					while (i-- >= 0)
						free(tabg[i]);
					return (NULL);
				}
			tabg[i] = ft_strcpy(tabg[i], s, c);
			i++;
		}
		s++;
	}
	tabg[i] = NULL;
	return (tabg);
}

int	main(void)
{
	char const s[] = "Bonjour-je-suis-un---pc";
	char	c = '-';
	char **new_str;

//	printf("%d\n", ft_count(s, c));
	new_str = ft_split(s, c);
	printf("%s\n", new_str[1]);
	free(new_str);
	return (0);
}
