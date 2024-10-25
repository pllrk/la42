/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:39:09 by plerick           #+#    #+#             */
/*   Updated: 2024/10/25 22:57:34 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>

int	get_len(int nb)
{
	int	len;
	long	num;

	len = 1;
	num = nb;
	if (num < 0)
	{
		len = len + 1;
		num = (num * - 1);
	}
	while (num >= 10)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int	len;

	len = get_len(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = (nb * - 1);
	}
	while (nb >= 10)
	{
		len--;
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	len--;
	str[len] = (nb + '0');
	return (str);
}
/*
int main(void)
{
	int	nb = -2214215;
	char	str[12];

	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-2147483648));
  
	printf("Test avec %d:\n", nb);
	sprintf(str, "%d", nb);
	printf("Mon ft_itoa : %s\n", ft_itoa(nb));
	printf("Vrai itoa  : %s\n", str);

	return (0);
}
*/
