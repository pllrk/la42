/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:56:45 by plerick           #+#    #+#             */
/*   Updated: 2024/11/11 21:58:14 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *s)
{
	int	i;	

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
/*
int	main(void)
{
//	char	c[] = "\0";

//	ft_printstr(NULL);
	ft_printf(" NULL %s NULL \n", NULL);
	printf(" NULL %s NULL ", (char *)NULL);
	return (0);
}
*/
