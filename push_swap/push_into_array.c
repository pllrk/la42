/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_into_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:54:36 by plerick           #+#    #+#             */
/*   Updated: 2025/02/05 18:56:41 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int *push_into_array(char **array)
{
    int *temp;

    while (array[i] != NULL)
	{
		temp[i] = push_atol(array[i]);
		i++;
		if (array_int[i] > INT_MAX || array_int[i] < INT_MIN)
			return (write(2, "Error\n", 6)); // must free l'array
	}
    return (temp);
}