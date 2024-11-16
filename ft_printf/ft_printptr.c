/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:11:13 by plerick           #+#    #+#             */
/*   Updated: 2024/11/12 14:19:00 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//#include <unistd.h>
//#include <stdio.h>

static void	my_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int	ft_printptr(void *ptr)
{
	int	i;
	unsigned long	num;
	char	temp[20];
	int	n;	
		
	num = (unsigned long)ptr;
	i = 0;
	n = 0;
	if (num == 0)
		return (write (1, "0x0", 3));
	while (num > 15)
	{
		if ((num % 16) < 10)
			temp[i++] = ((num % 16) + '0');
		else if ((num % 16) > 10)
			temp[i++] = ((num % 16) - 10 + 'a');
		num = num / 16;
	}
	write(1, "0x", 2);
	while (i > 0)
	{
		my_putchar(temp[i--]);
		n++;
	}
	return (n + 1);
}
/*
int	main(void)
{
	long	nb;

	nb = 0;
	printf("\n%d\n",ft_printptr((long *)nb));
	return (0);
}
*/
