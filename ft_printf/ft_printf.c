/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:17:28 by plerick           #+#    #+#             */
/*   Updated: 2024/11/07 22:15:04 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	my_check(va_list args, const char *str)
{
	int	i;
	int	fd;
	
	i = 0;
	fd = 1;
	if (str[i + 1] == 'c')
		ft_putchar_fd(va_arg(args, int), fd);
	else if (str[i + 1] == 's')
		ft_putstr_fd(va_arg(args, char *), fd);
	else if ((str[i + 1] == 'd') || (str[i + 1] == 'i'))
		ft_putnbr_fd(va_arg(args, int), fd);
	else if (str[i + 1] == '%')
		ft_putchar_fd('%', fd);

	else
		{
			ft_putchar_fd(str[i], fd);
			if (str[i + 1] != '\0')
				ft_putchar_fd(str[i + 1], fd);
		}
	return 0;
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	fd;
	
	i = 0;
	fd = 1;
	va_list args;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			my_check(args, &str[i]);
			i++;
		}
		else
			ft_putchar_fd(str[i], fd);
		if (str[i] != '\0')
			i++;
	}
	return (1);
}

int	main(void)
{
	int	i = 5;
	int	a = 'g';
	char s[] = "Haha";
	int	iii = 456;

	ft_printf("%c %s, % j'vai %d !%% % wooooow plein de chiffre %i", a, s, i, iii);
	return (0);
}
