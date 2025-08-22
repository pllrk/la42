
#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_fork
{
	int		id_fork;
	int		in_use;
	struct s_fork	*next;
	struct s_philo	*philo_to_right;
	struct s_philo	*philo_to_left;
	pthread_mutex_t mutex;
}					t_fork;

typedef struct s_philo
{
	int				id_philo;
	struct s_philo	*next;
	long			set_time_begin;
	long			last_time_eat;
	t_fork			*fork_right;
	t_fork			*fork_left;
	struct s_rules	*rules;
	int				dead; 
}					t_philo;

typedef struct s_rules
{
	long		nbr_of_philo;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_to_eat;
}					t_rules;

typedef struct s_all
{
	struct s_fork 	*forks;
	struct s_philo	*philos;
	struct s_rules	*rule;
}					t_all;


long	ft_atol(const char *str);
void	go_to_end(t_all *all,t_philo *philo, t_fork *fork);
void	free_all(t_all *all);
void	put_fork_on_table(t_philo *philo,t_fork *fork, t_all *all);
int		start_dinner(t_all *all);
long	get_time_begin(void);
void	philo_sleep(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_think(t_philo *philo);
long	check_time_eat(t_philo *philo);
int		check_end(t_philo *philo);
int		take_fork(t_philo *philo, t_fork *forks);
void	fork_toggle_available(t_fork *forks);
void	philo_wait(t_philo *philo, long wait_time);
long	get_time_event(t_philo *philo);

#endif
