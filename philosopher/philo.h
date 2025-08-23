/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:32:53 by plerick           #+#    #+#             */
/*   Updated: 2025/08/23 11:32:56 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_fork
{
	int				in_use;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_philo
{
	int				id_philo;
	struct s_philo	*next;
	long			set_time_begin;
	long			last_time_eat;
	t_fork			fork_right;
	t_fork			*fork_left;
	struct s_all	*rules;
	int				dead;
}					t_philo;

// typedef struct s_rules
// {
// 	long		nbr_of_philo;
// 	long		time_to_die;
// 	long		time_to_eat;
// 	long		time_to_sleep;
// 	long		nbr_to_eat;
// }					t_rules;

typedef struct s_all
{
	long			nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			nbr_to_eat;
}					t_all_rule;

long				ft_atol(const char *str);
void				go_to_end(t_philo *philo, t_philo *philo_t_add,
						t_fork *fork, t_fork *fork_t_add);
// void	go_to_end(t_philo *philo, t_fork *fork);
// void	free_all(t_all_rule *all);
void				put_fork_on_table(t_philo *philo, t_fork *fork);
void				start_dinner(t_all_rule *all, t_philo *philo,
						t_fork *fork_start);
long				get_time_begin(void);
void				philo_sleep(t_philo *philo);
void				philo_eat(t_philo *philo);
void				philo_think(t_philo *philo);
long				check_time_eat(t_philo *philo);
int					check_end(t_philo *philo);
int					pick_up_fork(t_philo *philo, t_fork *forks);
long				get_time_event(t_philo *philo);
int					check_overflaw(char **argv);
void				philo_stop(t_philo *philo, long wait_time);
void				fork_set_dispo(t_fork *forks);
int					create_fork_first(t_fork *fork, int i);
void				create_philo_first(t_all_rule *all, t_philo *philo_one,
						int i);

#endif
