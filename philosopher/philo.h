
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
	struct sphilo	*philo_using;
	struct sphilo	*philo_to_right;
	struct sphilo	*philo_to_left;
}					t_fork;

typedef struct s_philo
{
	int				id_philo;
	bool			eaten;
	bool			sleep;
	bool			think;
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

int		ft_atoi(const char *str);

#endif
