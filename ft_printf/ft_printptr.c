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

static void	my_putchar(char c)
{
		write(1, &c, 1);
		return ;
}

int	ft_printptr(void *ptr)
{
	int	i;
	unsigned long	ptr2;

	i = 0;
	ptr2 = (unsigned long)ptr;
	if (ptr2 < 0)
	{
		write(1, "-", 1);
		i++;
		ptr2 = ptr2 * -1;
	}
	if (ptr2 >= 0 && ptr2 < 16)
	{
		if (ptr2 < 10)
			my_putchar(ptr2 + '0');
		else
			my_putchar(ptr2 - 10 + 'a');
		return (i = i + 1);
	}
	else
	{
		i = i + (ft_printptr((void *)ptr2 / 16));
		ft_printptr((void *)ptr2 % 16);
		return (i + 1);
	}
}
/*
int	main(void)
{
	long	nb;

	nb = 4095;
	printf("\n%d\n",ft_printbase_lo(nb));
	return (0);
}
*/
