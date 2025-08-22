#include "philo.h"

long get_time_event(t_philo *philo)
{
	return (get_time_begin() - philo->set_time_begin);
}

int check_end(t_philo *philo)
{
	static int				end = 0;
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;
	int						is_dead;

	is_dead = 0;
	if (!philo->dead)
	{
		pthread_mutex_lock(&mutex);
		if (!end && check_time_eat(philo) <= 0)
		{
			is_dead = 1;
			end = 1;
		}
		philo->dead = end;
		pthread_mutex_unlock(&mutex);
		if (is_dead)
			printf("%ld philo n°%d is dead\n", get_time_event(philo), philo->id_philo);
	}
	return (philo->dead);
}

long check_time_eat(t_philo *philo)
{
	return (philo->rules->time_to_die - (get_time_begin() - philo->last_time_eat));
}

long get_time_begin(void)
{
	struct	timeval start;
	long	time_begin;

	gettimeofday(&start, NULL);
	time_begin = (start.tv_sec * 1000 + start.tv_usec / 1000);
	return (time_begin);
}

long	ft_atol(const char *str)
{
	int	i;
	long	neg;
	long	chif;

	i = 0;
	neg = 1;
	chif = 0;
	if (*str == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		chif = chif * 10 + (str[i] - '0');
		i++;
	}
	return (chif * neg);
}
