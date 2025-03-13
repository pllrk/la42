/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:42:44 by plerick           #+#    #+#             */
/*   Updated: 2025/03/13 22:45:27 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	verif_no_more(char *str[])
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

int	no_double(char *argv[])
{
	int	i;
	int	j;
	int	y;

	i = 0;
	j = 1;
	y = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		y = ft_atoi(argv[i]);
		while (argv[j] != NULL)
		{
			if (y != ft_atoi(argv[j]))
				j++;
			else
			{
				write(2, "error\n", 6);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	no_big(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if ((push_atol(argv[i]) > INT_MAX) || (push_atol(argv[i]) < INT_MIN))
		{
			write(2, "error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	no_char(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i] != NULL)
	{
		while (argv[i][j] != '\0')
		{
			if (((argv[i][j] == '-') || (argv[i][j] == '+')))
				j++;
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	verif_string(char *argv[])
{
	if ((no_char(argv) == 1) && (no_big(argv) == 1) && (no_double(argv) == 1))
		return (1);
	else
		return (0);
}
