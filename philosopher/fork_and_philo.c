
#include "philo.h"

void until_no_more_hungry(t_philo *philo)
{
	philo->set_time_begin = get_time_begin();
	
}

void until_it_dies(t_philo *philo)
{
	philo->set_time_begin = get_time_begin();
}

void *task_to_do(void *arg)
{
	t_philo *philo_thread;
	philo_thread = (t_philo *)arg;
	// mettre une sécu

	if (philo_thread->rules->nbr_to_eat == -1)
 		until_it_dies(philo_thread);
	else
		until_no_more_hungry(philo_thread);
	return (NULL);
}

int	start_dinner(t_all *all)
{
	pthread_t	philo_treh[all->rule->nbr_of_philo];
	// int			i;

	// i = 0;
	pthread_create(&philo_treh[0], NULL, task_to_do, all->philos);
	pthread_create(&philo_treh[1], NULL, task_to_do, all->philos->next);
	pthread_join(philo_treh[0], NULL);
	pthread_join(philo_treh[1], NULL);
	return (1);
}
