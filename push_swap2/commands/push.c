/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:14:35 by plerick           #+#    #+#             */
/*   Updated: 2025/03/10 18:15:28 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Prend le premier élément au sommet d'une pile et le met sur l'autre.*/

 void	push(t_list **dst, t_list **src) 
{
	t_list	*push_node;

	if (!*src) 
		return ;
	push_node = *src;
	*src = (*src)->next; 
	if (*src) 
		(*src)->previous = NULL; 
	push_node->previous = NULL; 
	if (!*dst) 
	{
		*dst = push_node; 
		push_node->next = NULL; 
	}
	else 
	{
		push_node->next = *dst; 
		push_node->next->previous = push_node;
		*dst = push_node;
	}
}

void	pa(t_list **a, t_list **b) //Push on top of `b`, the top `a` and print the instruction
{
	push(a, b); 
	write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a) //Push on top of `a`, the top `b` and print the instruction
{
	push(b, a);
	write(1, "pb\n", 3);
}
/*https://github.com/arommers/push_swap/blob/master/src/push.c*/
