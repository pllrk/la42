/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:06:07 by plerick           #+#    #+#             */
/*   Updated: 2024/11/18 21:09:24 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printuint(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 0 && nb < 10)
	{
		my_putchar(nb + '0');
		return (i = i + 1);
	}
	else
	{
		i = i + (ft_printuint(nb / 10));
		ft_printuint(nb % 10);
		return (i + 1);
	}
}
/*
int	main(void)
{
	int	nb;

	nb = 12;
	printf("\n%d\n",ft_printuint(nb));
	return (0);
}
*/
