/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:24:16 by plerick           #+#    #+#             */
/*   Updated: 2025/03/13 21:28:54 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier */
void	rotate(t_list **stack)
{
	t_list	*go_last;
	t_list	*go_debut;
	t_list	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	go_debut = *stack;
	go_last = *stack;
	tmp = *stack;
	tmp = tmp->next;
	while (go_last->next)
		go_last = go_last->next;
	go_debut->next = NULL;
	go_debut->previous = go_last;
	go_last->next = go_debut;
	tmp->previous = NULL;
	*stack = tmp;
}

void	ra(t_list **a) //Rotate top `a` to bottom of stack, print instruc
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b) //Rotate top `b` to bottom of stack, print instr
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b) //rotate `a``b` nodes at bot of stack
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
