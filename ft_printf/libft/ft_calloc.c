/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:01:04 by plerick           #+#    #+#             */
/*   Updated: 2024/11/05 02:41:35 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*my_memset(void *s, int c, size_t n)
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

	ptr = malloc(num * size);
	if (ptr == NULL)
		return (NULL);
	my_memset((int *)ptr, 0, (num * size));
	return (ptr);
}
/*
int	main(void)
{
	int	num_elements = 0;
	int	*array;
	int	i = 0;
	array = (int*)ft_calloc(num_elements, 0);
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
