/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_and_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:06:30 by plerick           #+#    #+#             */
/*   Updated: 2025/02/17 20:06:34 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	*free_all(char **tab, int argc)
{
	int i;

	i = argc;
	while (i >= 0)
		free(tab[i--]);
	free(tab);
	exit(1);
}

int	verif_and_all(int argc, char *argv[])
{
	char **a;

	if (argc < 2)
	{
		exit(0);
	}
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			exit(0);
		a = ft_split(argv[1], ' ');
		if (verif_string(a) == 0)
		{
			write(2, "error\n", 6);
			free_all(a, argc);
		}
		free_all(a, argc);
	}
	else if (verif_string(argv + 1) == 0)
	{
		ft_printf("error no string\n");
		exit(0);
	}
	return (1);
}