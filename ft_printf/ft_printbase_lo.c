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

#include "ft_printf.h"

static void	my_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int	ft_printbase_lo(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == '\0')
		return (write(1, "0", 1));
	if (nb >= 0 && nb < 16)
	{
		if (nb < 10)
			my_putchar(nb + '0');
		else
			my_putchar(nb - 10 + 'a');
		return (i = i + 1);
	}
	else
	{
		i = i + (ft_printbase_lo(nb / 16));
		ft_printbase_lo(nb % 16);
		return (i + 1);
	}
}
/*
int	main(void)
{
	long	nb;

	nb = 4095;
	ft_printf(" mon ft_printf %d\n",ft_printbase_lo(nb));
	printf(" Vrai printf %d\n",ft_printbase_lo(nb));
	ft_printf("%x\n", nb);
	printf("%x", (unsigned int)nb);
	printf("%d\n", ft_printf("%x\n", nb));
	ft_printf("%d", printf("%x\n", (unsigned int)nb));

//	ft_printf("mon ft_printf %x\n ", 4294967295);
//	printf("%x", (unsigned int)4294967295);
	printf("%d\n", ft_printf("%x", 4294967295));
	printf("%d", printf("%x", (unsigned int)4294967295));
	return (0);
}
*/
