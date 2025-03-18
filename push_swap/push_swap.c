/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:47:16 by plerick           #+#    #+#             */
/*   Updated: 2025/01/13 18:47:16 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_the_stack(t_list **a, t_list **b)
{
	if (!stack_sorted(*a))
	{
		if (stack_len(*a) == 2)
			sa(a);
		else if (stack_len(*a) == 3)
			sort_three(a);
		else
			sort_stack(a, b);
	}
}

void	add_last(t_list **a, t_list *new_node)
{
	t_list	*tmp;

	tmp = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		new_node->previous = NULL;
		return ;
	}
	else
	{
		tmp = *a;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new_node;
		new_node->previous = tmp;
	}
}

void	fill_stack_a(t_list **a, int argv, int i)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (free_all(a));
	new_node->value = argv;
	new_node->index = i;
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->cheapest = 0;
	add_last(a, new_node);
}

void	init_a(char **argv, t_list **a)
{
	int		chiffres;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[i] != NULL)
	{
		chiffres = ft_atoi(argv[i]);
		fill_stack_a(a, chiffres, j);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_list		*a;
	t_list		*b;
	int			i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (i != (verif_and_all(argc, argv)))
		exit(0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_a(argv, &a);
		free_split(argv);
	}
	else
		init_a(argv + 1, &a);
	sort_the_stack(&a, &b);
	free_all(&a);
	free_all(&b);
	return (0);
}

// Verif pour les chiffres plus grand que 12 je crois