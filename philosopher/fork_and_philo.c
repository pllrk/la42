/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:30:23 by plerick           #+#    #+#             */
/*   Updated: 2025/08/23 11:47:44 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	until_no_more_hungry(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->id_philo % 2)
	{
		philo_think(philo);
		philo_stop(philo, philo->rules->time_to_sleep);
		philo_eat(philo);
		i++;
		philo_sleep(philo);
	}
	while (!check_end(philo) && i < philo->rules->nbr_to_eat)
	{
		philo_think(philo);
		philo_eat(philo);
		i++;
		philo_sleep(philo);
	}
	return ;
}

void	until_it_dies(t_philo *philo)
{
	if (philo->id_philo % 2)
	{
		philo_think(philo);
		philo_stop(philo, philo->rules->time_to_sleep);
		philo_eat(philo);
		philo_sleep(philo);
	}
	while (!check_end(philo))
	{
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return ;
}

void	*task_to_do(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->set_time_begin = get_time_begin();
	philo->last_time_eat = philo->set_time_begin;
	if (philo->rules->nbr_to_eat == -1)
		until_it_dies(philo);
	else
		until_no_more_hungry(philo);
	return (NULL);
}

void	start_dinner(t_all_rule *all, t_philo *philo, t_fork *fork_start)
{
	pthread_t	philo_treh;
	t_philo		tmp;

	if (philo->id_philo <= all->nbr_of_philo)
	{
		if (philo->id_philo < all->nbr_of_philo)
		{
			create_philo_first(all, &tmp, philo->id_philo + 1);
			philo->fork_left = &tmp.fork_right;
			pthread_create(&philo_treh, NULL, &task_to_do, philo);
			start_dinner(all, &tmp, fork_start);
		}
		else
		{
			philo->fork_left = fork_start;
			pthread_create(&philo_treh, NULL, &task_to_do, philo);
		}
		pthread_join(philo_treh, NULL);
	}
}
