/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:56:45 by plerick           #+#    #+#             */
/*   Updated: 2024/11/04 20:38:42 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
void	my_toupper(unsigned int index, char *c) 
{
	(void)index;
	if (*c >= 'a' && *c <= 'z')
		*c = (*c - 32);
	return;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
/*
int	main(void)
{
	char	str[] = "couCou";
	
	ft_striteri(str, my_toupper);

	printf("%s\n", str);
	return (0);
}
*/
