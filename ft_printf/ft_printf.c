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
//	int	i = 5;
//	int	a = 'g';
//	char s[] = "Haha";
//	int	iii = 456;
	int	count = 0;
//	long	base1 = 1;
//	long	base2 = '\0';
	int	nbptr = 1;
	int	*ptr = &nbptr;

//	count = ft_printf("%c %s, % j'vai %d !%% % wooooow plein de chiffre %i\n", a, s, i, iii);
//	count = ft_printf("%s\n", s);
//	count = ft_printf("%s\n%X\n", (char *)NULL, base2);
	count = ft_printf("%p", ptr);
	ft_printf("%i", count);
	return (count);
}
