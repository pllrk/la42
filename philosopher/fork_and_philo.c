
#include "philo.h"

void put_fork_on_table(t_philo *philo,t_fork *fork, t_all *all)
{
	t_philo *tmp;
	t_fork 	*tmp2;

	tmp = philo;
	tmp2 = fork;
	while (tmp->next)
	{
		tmp->fork_right = tmp2;
		tmp2->philo_to_left = tmp;
		tmp = tmp->next;
		tmp2->philo_to_right = tmp;
		tmp->fork_left = tmp2;
		tmp2 = tmp2->next;
	}
	tmp->fork_right = tmp2;
	tmp2->philo_to_left = tmp;
	tmp2->philo_to_right = all->philos;
	all->philos->fork_left = tmp2;
}
