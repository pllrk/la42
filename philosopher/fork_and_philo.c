
#include "philo.h"

void until_no_more_hungry(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->id_philo % 2)
	{
		philo_think(philo);
		philo_wait(philo, philo->rules->time_to_sleep);
		philo_eat(philo);
		i++;
		philo_sleep(philo);
	}
	while (!check_end(philo) && i < philo->rules->nbr_to_eat)
	{
		philo_think(philo);
		philo_wait(philo, philo->rules->time_to_sleep);
		philo_eat(philo);
		i++;
		philo_sleep(philo);
	}
	return ;
}

void until_it_dies(t_philo *philo)
{
	if (philo->id_philo % 2)
	{
		philo_think(philo);
		philo_wait(philo, philo->rules->time_to_sleep);
		philo_eat(philo);
		philo_sleep(philo);
	}
	while (!check_end(philo))
	{
		philo_think(philo);
		philo_wait(philo, philo->rules->time_to_sleep);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return ;
}

void *task_to_do(void *arg)
{
	t_philo *philo;
	philo = arg;
	philo->set_time_begin = get_time_begin();
	philo->last_time_eat = philo->set_time_begin;
	if (philo->rules->nbr_to_eat == -1)
 		until_it_dies(philo);
	else
		until_no_more_hungry(philo);
	return (NULL);
}

int	start_dinner(t_all *all)
{
	pthread_t	philo_treh[all->rule->nbr_of_philo];
	t_philo		*tmp;
	int			i;

	i = 0;
	tmp = all->philos;
	while (i < all->rule->nbr_of_philo)
	{
		pthread_create(&philo_treh[i], NULL, &task_to_do, tmp);
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while(i < all->rule->nbr_of_philo)
	{
		pthread_join(philo_treh[i], NULL);
		i++;
	}	
	//here need to destroy the mutex
	return (1);
}
