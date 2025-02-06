/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfo_str_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:31:32 by plerick           #+#    #+#             */
/*   Updated: 2025/02/06 19:47:22 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *transfo_str_int(char **array)
{
	int	i;
	int	*array_int;

	if (check_array_ok(array) == 0)
	{
		free(array); //faire ft_free
		write(2, "Error\n", 6);
		exit;
	}
	i = 0;
	while (array[i] != NULL)
		i++;
	array_int = malloc(sizeof(long) * i); //faire la verif malloc apres
	array_int = push_into_array(array);
}