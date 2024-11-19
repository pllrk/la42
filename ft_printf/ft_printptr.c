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

#include "ft_printf.h"

int	ft_printptr(void *ptr)
{
	int				i;
	unsigned long	num;
	char			temp[20];
	int				n;	

	num = (unsigned long)ptr;
	i = 0;
	n = 0;
	if (num == '\0')
		return (write (1, "(nil)", 5));
	while (num > 0)
	{
		if ((num % 16) < 10)
			temp[i++] = ((num % 16) + '0');
		else if ((num % 16) >= 10)
			temp[i++] = ((num % 16) - 10 + 'a');
		num = num / 16;
	}
	n += write(1, "0x", 2);
	while (i > 0)
		n += ft_printchar(temp[--i]);
	return (n);
}
/*
int	main(void)
{
	char	*nb;

	nb = "salut";
	ft_printf("\n%d\n\n",ft_printptr(nb));
	printf("\n%d\n",ft_printptr(nb));
	printf("Mon ft_printf\n%d", ft_printf("\n%p\n", nb));
	printf("Vrai printf\n%d", printf("\n%p\n", nb));
	ft_printf("%p %p", (void *)0, (void *)0);
	printf("%p %p", (void *)0, (void *)0);
	ft_printf("%d", ft_printf("%p %p", (void *)0, (void *)0));
	printf("%d", printf("%p %p", (void *)0, (void *)0));
	return (0);
}
*/
