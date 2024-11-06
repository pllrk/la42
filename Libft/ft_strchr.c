/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:04:16 by plerick           #+#    #+#             */
/*   Updated: 2024/10/28 19:17:41 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t			i;
	unsigned char	vc;

	i = 0;
	vc = (unsigned char) c;
	while (str[i] != '\0')
	{
		if (vc == str[i])
			return (&(((char *)str)[i]));
		i++;
	}
	if (vc == '\0' && str[i] == '\0')
		return (&(((char *)str)[i]));
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "abc";
	int	c = 'b';
	const char	str2[] = "abc";
	int	c2 = 'b';


	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str2, c2));
	return (0);
}
*/
