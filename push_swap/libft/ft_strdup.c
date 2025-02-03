/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:08:20 by plerick           #+#    #+#             */
/*   Updated: 2025/02/03 20:15:05 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\0')
		i++;
	new_str = (char *)malloc((sizeof(char) * i) + 1);
	if (new_str == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_str[j] = str[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}
/*
int	main(void)
{
	const char	str1[] = "hahaha";
	const char	str2[] = "ha";
	const char	*dup1;
	const char	*dup2;

	dup1 = ft_strdup(str1);
	dup2 = strdup(str2);
	printf("Mon code : %s\n", dup1);
	printf("La verif : %s\n", dup2);
	free((void *)dup1);
	free((void *)dup2);
	return (0);
}
*/
