/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:48:23 by plerick           #+#    #+#             */
/*   Updated: 2025/03/13 21:13:00 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_check_nof(const char *str)
{
	int	count;

	count = 0;
	count += ft_printchar(str[0]);
	if (str[1] != '\0')
		count += ft_printchar(str[1]);
	return (count);
}

static int	my_check(va_list args, const char *str)
{
	int	count;

	count = 0;
	if (str[1] == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (str[1] == 's')
		count += ft_printstr(va_arg(args, char *));
	else if ((str[1] == 'd') || (str[1] == 'i'))
		count += ft_printnbr(va_arg(args, int));
	else if (str[1] == '%')
		count += ft_printchar('%');
	else if (str[1] == 'x')
		count += ft_printbase_lo(va_arg(args, long));
	else if (str[1] == 'X')
		count += ft_printbase_up(va_arg(args, long));
	else if (str[1] == 'p')
		count += ft_printptr(va_arg(args, void *));
	else if (str[1] == 'u')
		count += ft_printuint(va_arg(args, unsigned int));
	else
		my_check_nof(str);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
			count = count + (my_check(args, &str[i++]));
		else
		{
			ft_printchar(str[i]);
			count++;
		}
		if (str[i] != '\0')
			i++;
	}
	va_end(args);
	return (count);
}
