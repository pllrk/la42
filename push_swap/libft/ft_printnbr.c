/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 21:31:14 by plerick           #+#    #+#             */
/*   Updated: 2024/11/11 21:31:55 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		i++;
		nb = nb * -1;
	}
	if (nb >= 0 && nb < 10)
	{
		my_putchar(nb + '0');
		return (i = i + 1);
	}
	else
	{
		i = i + (ft_printnbr(nb / 10));
		ft_printnbr(nb % 10);
		return (i + 1);
	}
}
/*
int	main(void)
{
	int	nb;

	nb = 12;
	printf("\n%d\n",ft_printnbr(nb));
	return (0);
}
*/
