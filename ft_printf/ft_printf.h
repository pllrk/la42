/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:42:29 by plerick           #+#    #+#             */
/*   Updated: 2024/11/18 21:42:34 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printnbr(int nb);
int	ft_printstr(char *s);
int	ft_printbase_lo(long nb);
int	ft_printbase_up(long nb);
int	ft_printptr(void *ptr);
int	ft_printuint(unsigned int nb);

#endif
