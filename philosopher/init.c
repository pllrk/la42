/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:30:38 by plerick           #+#    #+#             */
/*   Updated: 2025/08/23 11:30:42 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_fork(t_fork *fork)
{
	pthread_mutex_init(&fork->mutex, NULL);
	fork->in_use = 0;
}

void	create_philo_first(t_all_rule *all, t_philo *philo_one, int i)
{
	create_fork(&philo_one->fork_right);
	philo_one->id_philo = i;
	philo_one->next = NULL;
	philo_one->fork_left = NULL;
	philo_one->rules = all;
	philo_one->set_time_begin = 0;
	philo_one->last_time_eat = 0;
	philo_one->dead = 0;
	return ;
}
