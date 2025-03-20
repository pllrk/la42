/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:40:17 by plerick           #+#    #+#             */
/*   Updated: 2025/03/20 18:22:02 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int	id;
	int	n;
	int	i = 1;

	id = fork();
	// ft_printf("id est : %d \n", id);
	if(id == 0)
	{
		// ft_printf("coucou du child, mon ID est : %d\n", id);
		n = 1;
	}		
	else
	{
		// ft_printf("coucou du parent, mon ID est : %d\n", id);
		n = 5;
	}
	i = n;
	while (i + 5 > n)
	{
		ft_printf("%d ", n);
		n++;
	}
	if(id != 0)
		wait(0);
	return (0);
}	