/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:17:28 by plerick           #+#    #+#             */
/*   Updated: 2024/11/16 22:22:14 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	my_check(va_list args, const char *str)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	if (str[i + 1] == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (str[i + 1] == 's')
		count += ft_printstr(va_arg(args, char *));
	else if ((str[i + 1] == 'd') || (str[i + 1] == 'i'))
		count += ft_printnbr(va_arg(args, int));
	else if (str[i + 1] == '%')
		count += ft_printchar('%');
	else if (str[i + 1] == 'x')
		count += ft_printbase_lo(va_arg(args, long));
	else if (str[i + 1] == 'X')
		count += ft_printbase_up(va_arg(args, long));
 	else if (str[i + 1] == 'p')
		count += ft_printptr(va_arg(args, void*));	
		
	else
		{
			count += ft_printchar(str[i]);
			if (str[i + 1] != '\0')
				count += ft_printchar(str[i + 1]);
		}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	va_list args;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = count + (my_check(args, &str[i]));
			i++;
		}
		else
		{
			ft_printchar(str[i]);
			count++;
		}
		if (str[i] != '\0')
			i++;
			
	}
	return (count);
}

int	main(void)
{
	int	d = 5;
	int	c = 'g';
	char s[] = "Haha";
	int	iii = 455;
	int	count = 0;
	unsigned int	base1 = 255;
	unsigned int	base2 = 4095;
	int	nbptr = 1;
	int	*ptr = &nbptr;

	count = ft_printf("c : %c\ns : %s\nd : %d\npourcent: %%\ni : %i\nx : %x\nX : %X\np : %p\n", c, s, d, iii, base1, base2, ptr);
	ft_printf("Mon printf : %i\n\n", count);
	count = printf("c : %c\ns : %s\nd : %d\npourcent : %%\ni : %i\nx : %x\nX : %X\np : %p\n", c, s, d, iii, base1, base2, ptr);
	printf("Vrai printf : %i\n", count);
	return (count);
}
