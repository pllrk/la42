/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:25:23 by plerick           #+#    #+#             */
/*   Updated: 2024/10/21 19:22:06 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
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
/*
int	main(void)
{
	char	lol[] =  "    -+-+-+-+-++++------+---+45654645wf65421";
	char	lol1[] =  "231";
	char	lol2[] =  " -421";
	char	lol3[] =  "+5654645wf65421";
	char	lol4[] =  "-2147483648";


	ft_atoi(lol);
	printf("%d\n", ft_atoi(lol));
	printf("%d\n", ft_atoi(lol1));
	printf("%d\n", ft_atoi(lol2));
	printf("%d\n", ft_atoi(lol3));
	printf("%d\n", ft_atoi(lol4));
	printf("%d\n", atoi(lol4));	
	return (0);
}
*/
