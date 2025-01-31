/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_array_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:02:16 by plerick           #+#    #+#             */
/*   Updated: 2025/01/31 17:02:31 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_array_size(char *argv)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;

	while (argv[i] == ' ')
		i++;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) == 1)
			count++;
		while (argv[i] != ' ' && argv[i] != '\0')
			i++;
		if (argv[i] == '\0')
			return (count);
		i++;
	}
	return(count);
	// Calculer la taille de l'array à partir du nombre de virgule ou d'espace, il faut voir par rapport au sujet
}