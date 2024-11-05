/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:51:38 by plerick           #+#    #+#             */
/*   Updated: 2024/11/04 19:03:39 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_null(char **tabg, int i)
{
	while (i-- >= 0)
		free(tabg[i]);
	free(*tabg);
	return (NULL);
}

static char	*ft_strcpy(char const *start, int temp)
{
	int		i;
	char	*to_return;

	i = 0;
	to_return = (char *)malloc(sizeof(char) * (temp + 1));
	if (to_return == NULL)
		return (NULL);
	while (i < temp)
	{
		to_return[i] = start[i];
		i++;
	}
	to_return[i] = '\0';
	return (to_return);
}

static int	ft_count(char const *s, char c)
{
	int		count;
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
	size_t	temp;
	char	**tabg;
	int		i;
	size_t	start;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	tabg = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (tabg == NULL)
		return (NULL);
	while (s[start])
	{
		while (s[start] == c)
			start++;
		temp = 0;
		while (s[start + temp] && s[start + temp] != c)
			temp++;
		if (s[start])
			tabg[i++] = ft_strcpy(&s[start], temp);
		start = start + temp;
	}
	tabg[i] = NULL;
	return (tabg);
}
/*
int	main(void)
{
	char const s[] = "\0aa\0bbb";
	char	c = '\0';
	char **new_str;
	int	i = 0;

	new_str = ft_split(s, c);
	while (new_str[i] != NULL)
	{
		printf("%s\n", new_str[i]);
		free(new_str[i]);
		i++;
	}
	free(new_str);
	return (0);
}
*/
