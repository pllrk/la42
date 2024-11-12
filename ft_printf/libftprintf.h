/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:14:08 by plerick           #+#    #+#             */
/*   Updated: 2024/11/07 19:16:13 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_printchar(char c);
int	ft_printnbr(int nb);
int	ft_printstr(char *s);
int	ft_printbase_lo(long nb);
int	ft_printbase_up(long nb);
int	ft_printptr(void *ptr);

#endif
