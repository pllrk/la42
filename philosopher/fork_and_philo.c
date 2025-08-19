
#include "philo.h"

void* task_to_do(void *arg)
{
	t_philo *philo_thread;
	philo_thread = (t_philo *)arg;
	printf("id : %d\n", philo_thread->id_philo);
	return (NULL);
}

int	start_dinner(t_all *all)
{
	pthread_t philo_treh[all->rule->nbr_of_philo];
	
	pthread_create(&philo_treh[0], NULL, task_to_do, &all->philos);
	pthread_create(&philo_treh[1], NULL, task_to_do, &all->philos->next);
	// pthread_join(philo_treh[0], NULL);
	// pthread_join(philo_treh[1], NULL);
	return (1);
}
