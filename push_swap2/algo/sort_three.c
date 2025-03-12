/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:24:12 by plerick           #+#    #+#             */
/*   Updated: 2025/03/12 17:37:35 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	t_list	*big_node;

	big_node = find_big(*a);
	if (big_node == *a)
		ra(a);
	else if ((*a)->next == big_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}