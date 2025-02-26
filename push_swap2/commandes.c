/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:40:20 by plerick           #+#    #+#             */
/*   Updated: 2025/02/26 19:46:46 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Intervertit les 2 premiers éléments au sommet de la pile a*/
void sa(t_list **a)
{
	t_list *go_last;
	t_list *go_debut;
	t_list *tmp;

	tmp = NULL;
	go_debut = *a;
	go_last = *a;
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
	*a = go_last;
}

/* Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier */
void ra(t_list **a)
{
	t_list *go_last;
	t_list *go_debut;
	t_list *tmp;

	go_debut = *a;
	go_last = *a;
	tmp = *a;
	tmp = tmp->next;
	while (go_last->next)
			go_last = go_last->next;
	go_debut->next = NULL;
	go_debut->previous = go_last;
	go_last->next = go_debut;
	tmp->previous = NULL;
	*a = tmp;	
}


/* Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier */
void rra(t_list **a)
{
	t_list *go_last;
	t_list *go_debut;
	t_list *tmp;

	go_debut = *a;
	go_last = *a;
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
	*a = go_last;
}

/*Prend le premier élément au sommet de a et le met sur b.
Ne fait rien si a est vide.*/
void pb(t_list **a, t_list **b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*go_last;

	tmp_a = *a;
	go_last = *a;
	tmp_b = *b;

	
	if (tmp_a->next == NULL)
	{
		*b = tmp_a;
		*a = NULL;
		return;
	}
	if (tmp_b->next == NULL)
	{
		tmp_a->next = NULL;
		tmp_a->previous = NULL;
	}


}