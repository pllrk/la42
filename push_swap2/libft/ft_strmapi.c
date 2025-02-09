/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:21:14 by plerick           #+#    #+#             */
/*   Updated: 2024/11/04 19:22:02 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static char	my_toupper(unsigned int index, char c) 
{
	(void)index;
	if (c >= 'a' && c <= 'z')
		return c - ('a' - 'A'); // Convertit en majuscule
	return c;
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*new_str;
	size_t	i;

	len = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[len])
		len++;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	char	str[] = "Coucou";
	char	*new_str;

	new_str = ft_strmapi(str, my_toupper);

	printf("%s\n", new_str);
	free(new_str);
	return (0);
}
*/
