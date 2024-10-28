/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:01:04 by plerick           #+#    #+#             */
/*   Updated: 2024/10/28 22:46:28 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>
//#include <stdio.h>
//#include <stdlib.h>

static void	*memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num == 0 || size == 0)
		return (NULL);
	if ((ptr = malloc(num * size)) == NULL)
		return (NULL);
	memset((int *)ptr, 0, (num * size));
	return (ptr);
}
/*
int	main(void)
{
	int	num_elements = 5;
	int	*array;
	int	i = 0;
	array = (int*)ft_calloc(num_elements, sizeof(int));
	if (array == NULL) 
	{
        	printf("echec de l'allocation de memoire.\n");
        	return (0);
	}
	while (i < num_elements)
	{
		printf("array[%d] = %d\n", i, array[i]);
		i++;
	}	
	free(array);
	return (0);
}
*/
