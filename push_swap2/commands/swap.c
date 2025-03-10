/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:34:53 by plerick           #+#    #+#             */
/*   Updated: 2025/03/10 19:50:08 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Intervertit les 2 premiers éléments au sommet de la pile a*/
void	swap(t_list **stack)
{
	t_list *go_last;
	t_list *go_debut;
	t_list *tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = NULL;
	go_debut = *stack;
	go_last = *stack;
	go_last = go_last->next;
	if (go_last->next != NULL)
	{
		tmp = go_last;
		tmp = tmp->next;
		go_debut->next = go_last->next;
		go_last->next = go_debut;
		go_last->previous = NULL;
		go_debut->previous = go_last;
		tmp->previous = go_debut;
	}
	else
	{
		go_last->next = go_debut;
		go_debut->next = NULL;
		go_last->previous = NULL;
		go_debut->previous = go_last;
	}
	*stack = go_last;
}

void	sa(t_list	**a) //Swap the first two nodes of stack `a` and print the instruction
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b) //Swap the first two nodes of stack `b` and print the instruction
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b) //Stimutaneously swap the first two nodes of the stack and print the instruction
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}