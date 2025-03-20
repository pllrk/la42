/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbase_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:45:39 by plerick           #+#    #+#             */
/*   Updated: 2024/11/12 00:45:54 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	my_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

int	ft_printbase_up(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == '\0')
		return (write(1, "0", 1));
	if (nb < 16)
	{
		if (nb < 10)
			my_putchar(nb + '0');
		else if ((nb > 9) && (nb < 16))
			my_putchar(nb - 10 + 'A');
		return (i = i + 1);
	}
	else
	{
		i = i + (ft_printbase_up(nb / 16));
		ft_printbase_up(nb % 16);
		return (i + 1);
	}
}
/*
int	main(void)
{
	long	nb;

	nb = 4095;
	printf("\n%d\n",ft_printbase_up(nb));
	return (0);
}
*/
