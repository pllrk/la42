
#include "philo.h"

void pick_fork_left_first(t_philo *philo)
{
	if (take_fork(philo, philo->fork_left))
	{
		if (take_fork(philo, philo->fork_right))
		{
			if (!check_end(philo))
			{
				printf("%ld philo n°%d is eating\n", get_time_event(philo), philo->id_philo);
				philo->last_time_eat = get_time_begin();
				philo_wait(philo, philo->rules->time_to_eat);
			}
			fork_toggle_available(philo->fork_right);
		}
		fork_toggle_available(philo->fork_left);
	}
}

void pick_fork_right_first(t_philo *philo)
{
	if (take_fork(philo, philo->fork_right))
	{
		if (take_fork(philo, philo->fork_left))
		{
			if (!check_end(philo))
			{
				printf("%ld philo n°%d is eating\n", get_time_event(philo), philo->id_philo);
				philo->last_time_eat = get_time_begin();
				philo_wait(philo, philo->rules->time_to_eat);
			}
			fork_toggle_available(philo->fork_left);
		}
		fork_toggle_available(philo->fork_right);
	}
}

void philo_think(t_philo *philo)
{
	if (!check_end(philo))
		printf("%ld philo n°%d is thinking\n", get_time_event(philo), philo->id_philo);
}

void philo_eat(t_philo *philo)
{
	if (philo->fork_left->id_fork > philo->fork_right->id_fork)
		pick_fork_left_first(philo);
	else
		pick_fork_right_first(philo);
}

void philo_sleep(t_philo *philo)
{
	if (!check_end(philo))
	{
		printf("%ld philo n°%d is sleeping\n", get_time_event(philo), philo->id_philo);
		philo_wait(philo, philo->rules->time_to_sleep);
	}
}
