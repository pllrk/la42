/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:37:27 by plerick           #+#    #+#             */
/*   Updated: 2025/02/04 18:45:00 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long push_atol(const char *str)
{
	int	i;
	int	neg;
	int	chif;

	i = 0;
	neg = 1;
	chif = 0;
	if (*str == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		chif = chif * 10 + (str[i] - '0');
		i++;
	}
	return (chif * neg);
}