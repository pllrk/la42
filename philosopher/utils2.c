/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:31:01 by plerick           #+#    #+#             */
/*   Updated: 2025/08/23 11:33:56 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_overflaw(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

void	philo_stop(t_philo *philo, long wait_time)
{
	long	time_it_die;

	time_it_die = check_time_eat(philo);
	if (time_it_die < wait_time)
		wait_time = time_it_die;
	if (0 < wait_time)
		usleep(wait_time * 1000);
}

void	fork_set_dispo(t_fork *forks)
{
	pthread_mutex_lock(&forks->mutex);
	forks->in_use = !forks->in_use;
	pthread_mutex_unlock(&forks->mutex);
}

int	fork_check_dispo(t_fork *forks)
{
	int	is_available;

	pthread_mutex_lock(&forks->mutex);
	is_available = forks->in_use;
	pthread_mutex_unlock(&forks->mutex);
	return (is_available);
}

int	pick_up_fork(t_philo *philo, t_fork *forks)
{
	while (fork_check_dispo(forks) && !check_end(philo))
		usleep(100);
	if (!check_end(philo))
	{
		fork_set_dispo(forks);
		printf("%ld philo n°%d took a fork\n", get_time_event(philo),
			philo->id_philo);
		return (1);
	}
	return (0);
}
