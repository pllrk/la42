/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array_ok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:02:26 by plerick           #+#    #+#             */
/*   Updated: 2025/02/03 19:26:44 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_array_ok(char **array)
{
    int	i;
    int j;

	i = 0;
    j = 0;
    while (array[i] != NULL)
    {
        while (array[i][j] != '\0')
        {
            if (ft_isdigit(array[i][j]) == 1)
                 j++;
            else
                return (0);
        }
        i++;
        j = 0;
    }
    return (1);
}