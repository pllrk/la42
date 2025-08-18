
#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_fork
{
	int		id_fork;
	bool	in_use;
	struct s_fork	*next;
	struct s_philo	*philo_using;
	struct s_philo	*philo_to_right;
	struct s_philo	*philo_to_left;
}					t_fork;

typedef struct s_philo
{
	int				id_philo;
	bool			eaten;
	bool			sleep;
	bool			think;
	struct s_philo	*next;
	t_fork			*fork_right;
	t_fork			*fork_left;
	struct s_rules	*rules;
}					t_philo;

typedef struct s_rules
{
	int		nbr_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nbr_to_eat;
}					t_rules;

typedef struct s_all
{
	struct s_fork 	*forks;
	struct s_philo	*philos;
	struct s_rules	*rule;
}					t_all;


int		ft_atoi(const char *str);
void	go_to_end(t_all *all,t_philo *philo, t_fork *fork);
void	free_all(t_all *all);
void	put_fork_on_table(t_philo *philo,t_fork *fork, t_all *all);
#endif
