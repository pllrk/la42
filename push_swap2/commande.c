
#include "push_swap.h"

void	sa(t_list **a)
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