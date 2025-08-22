
#include "philo.h"

void philo_wait(t_philo *philo, long wait_time)
{
	long	time_it_die;

	time_it_die = check_time_eat(philo);
	if (time_it_die < wait_time)
		wait_time = time_it_die;
	if (0 < wait_time)
		usleep(wait_time * 1000);
}

void fork_toggle_available(t_fork *forks)
{
	pthread_mutex_lock(&forks->mutex);
	forks->in_use = !forks->in_use;
	pthread_mutex_unlock(&forks->mutex);
}

int	fork_is_available(t_fork *forks)
{
	int	is_available;

	pthread_mutex_lock(&forks->mutex);
	is_available = forks->in_use;
	pthread_mutex_unlock(&forks->mutex);
	return (is_available);
}

int	take_fork(t_philo *philo, t_fork *forks)
{
	while (fork_is_available(forks) && !check_end(philo))
		usleep(100);
	if (!check_end(philo))
	{
		fork_toggle_available(forks);
		printf("%ld philo n°%d took a fork\n", get_time_event(philo), philo->id_philo);
		return (1);
	}
	return (0);
}