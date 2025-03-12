/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:24:16 by plerick           #+#    #+#             */
/*   Updated: 2025/03/10 19:32:36 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier */

void rotate(t_list **stack)
{
	t_list *go_last;
	t_list *go_debut;
	t_list *tmp;

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
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

void	ra(t_list **a) //Rotate the top `a` node to the bottom of the stack, and print the instruction
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b) //Rotate the top `b` node to the bottom of the stack, and print the instruction
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b) //Stimultaneously rotate both the top `a` and `b` nodes to the bottom of the stack, and print the instruction
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
