/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:18:10 by plerick           #+#    #+#             */
/*   Updated: 2025/03/10 19:26:16 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier */
void	rev_rotate(t_list **stack)
{
	t_list *go_last;
	t_list *go_debut;
	t_list *tmp;

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	go_debut = *stack;
	go_last = *stack;
	while (go_last->next)
		{
			go_last = go_last->next;
			if (go_last->next != NULL)
				tmp = go_last;
		}
	go_last->previous = NULL;
	go_last->next = go_debut;
	go_debut->previous = go_last;
	tmp->next = NULL;
	*stack = go_last;
}

void	rra(t_list **a) 
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b) 
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}