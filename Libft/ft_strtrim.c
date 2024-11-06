/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:51:24 by plerick           #+#    #+#             */
/*   Updated: 2024/10/31 05:02:25 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cpy_str_trim(const char *s1, size_t len_str, size_t count1)
{
	char			*new_str;
	size_t			n;

	n = 0;
	new_str = (char *)malloc(sizeof(char) * len_str + 1);
	if (new_str == NULL)
		return (NULL);
	while (s1[count1] != '\0' && n < len_str)
	{
		new_str[n] = s1[count1];
		n++;
		count1++;
	}
	new_str[n] = '\0';
	return (new_str);
}

static int	limit_trim(const char s, const char *set)
{
	while (*set)
	{
		if (*set == s)
			return (1);
		set++;
	}
	return (0);
}

static int	my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count1;
	size_t	count2;
	size_t	len_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	count1 = 0;
	count2 = my_strlen(s1) - 1;
	while (s1[count1] != '\0')
	{
		if (limit_trim(s1[count1], set))
			count1++;
		else
			break ;
	}
	while (count2 > count1)
	{
		if (limit_trim(s1[count2], set))
			count2--;
		else
			break ;
	}
	len_str = count2 - count1 + 1;
	return (cpy_str_trim(s1, len_str, count1));
}
/*
int	main(void)
{
	char const s1[] = "***+Bonj+our!+++";
	char const set[] = "*+";
	char *trimmed;

	trimmed = ft_strtrim(s1, set);

        printf("Chaîne trimée : '%s'\n", trimmed);
        free(trimmed);
	return (0);
}
*/
