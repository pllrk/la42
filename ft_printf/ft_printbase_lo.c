/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase_lo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:53:51 by plerick           #+#    #+#             */
/*   Updated: 2024/11/12 00:42:15 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	my_putchar(char c)
{
		write(1, &c, 1);
		return ;
}

int	ft_printbase_lo(long nb)
{
	int	i;
	long	nbl;

	i = 0;
	nbl = (long)nb;
	if (nbl < 0)
	{
		write(1, "-", 1);
		i++;
		nbl = nbl * -1;
	}
	if (nbl >= 0 && nbl < 16)
	{
		if (nbl < 10)
			my_putchar(nbl + '0');
		else
			my_putchar(nbl - 10 + 'a');
		return (i = i + 1);
	}
	else
	{
		i = i + (ft_printbase_lo(nbl / 16));
		ft_printbase_lo(nbl % 16);
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
