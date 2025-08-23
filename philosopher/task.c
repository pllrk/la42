/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:30:56 by plerick           #+#    #+#             */
/*   Updated: 2025/08/23 11:30:58 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_fork_right_first(t_philo *philo)
{
	if (pick_up_fork(philo, &philo->fork_right))
	{
		if (pick_up_fork(philo, philo->fork_left))
		{
			if (!check_end(philo))
			{
				printf("%ld philo n°%d is eating\n", get_time_event(philo),
					philo->id_philo);
				philo->last_time_eat = get_time_begin();
				philo_stop(philo, philo->rules->time_to_eat);
			}
			fork_set_dispo(philo->fork_left);
		}
		fork_set_dispo(&philo->fork_right);
	}
}

void	philo_think(t_philo *philo)
{
	if (!check_end(philo))
		printf("%ld philo n°%d is thinking\n", get_time_event(philo),
			philo->id_philo);
}

void	philo_eat(t_philo *philo)
{
	pick_fork_right_first(philo);
}

void	philo_sleep(t_philo *philo)
{
	if (!check_end(philo))
	{
		printf("%ld philo n°%d is sleeping\n", get_time_event(philo),
			philo->id_philo);
		philo_stop(philo, philo->rules->time_to_sleep);
	}
}
