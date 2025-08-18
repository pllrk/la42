#include "philo.h"

void go_to_end(t_all *all,t_philo *philo, t_fork *fork)
{
	t_philo	*tmp;
	t_fork	*tmp2;

	if (philo != NULL)
	{
		(void)tmp2;
		tmp = all->philos;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = philo;
	}
	else
	{
		(void)tmp;
		tmp2 = all->forks;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = fork;
	}	
}


void free_philo(t_philo *philo, t_all *all)
{
	t_philo *tmp;

	tmp = philo;
	while (tmp->next)
	{
		tmp = tmp->next;
		free(all->philos);
		all->philos = tmp;
	}
	free(all->philos);
	all->philos = NULL;
}


void free_fork(t_fork *fork, t_all *all)
{
	t_fork *tmp;

	tmp = fork;
	while (tmp->next)
	{
		tmp = tmp->next;
		free(all->forks);
		all->forks = tmp;
	}
	free(all->forks);
	all->forks = NULL;
}

void free_all(t_all *all)
{
	free_fork(all->forks, all);
	free_philo(all->philos, all);
	free(all->rule);
	all->rule = NULL;
	all = NULL;
}
