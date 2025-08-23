/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:30:52 by plerick           #+#    #+#             */
/*   Updated: 2025/08/23 11:30:53 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_and_fork(t_all_rule *all)
{
	t_philo	philo;

	create_philo_first(all, &philo, 1);
	start_dinner(all, &philo, &philo.fork_right);
	return (0);
}

int	pass_rules(char **argv, t_all_rule *all)
{
	memset(all, 0, sizeof(t_all_rule));
	all->nbr_of_philo = ft_atol(argv[1]);
	all->time_to_die = ft_atol(argv[2]);
	all->time_to_eat = ft_atol(argv[3]);
	all->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		all->nbr_to_eat = ft_atol(argv[5]);
	else
		all->nbr_to_eat = -1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_all_rule	all;

	if (argc < 5 || argc > 6)
		return (write(2, "Not enough arguments\n", 21), 0);
	if (argv[1] == NULL || ft_atol(argv[1]) == 0 || check_overflaw(argv))
		return (write(2, "Bad arguments\n", 14), 0);
	pass_rules(argv, &all);
	create_philo_and_fork(&all);
	return (0);
}
