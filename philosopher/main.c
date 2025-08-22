#include "philo.h"
#include <pthread.h>

int create_fork(t_all *all, int i)
{
	t_fork *fork;

	fork = malloc(sizeof(t_fork));
	// mettre une sécu
	fork->id_fork = i;
	fork->in_use = 0;
	fork->next = NULL;
	fork->philo_to_left = NULL;
	fork->philo_to_right = NULL;
	pthread_mutex_init(&fork->mutex, NULL);
	if (!all->forks)
		all->forks = fork;
	else
		go_to_end(all, NULL, fork);
	return (0);
}

void create_philo(t_all *all, int i)
{
	t_philo *philo;


	philo = malloc(sizeof(t_philo));
	// mettre une sécu
	philo->id_philo = i;
	philo->next = NULL;
	philo->fork_left = NULL;
	philo->fork_right = NULL;
	philo->rules = all->rule;
	philo->set_time_begin = 0;
	philo->last_time_eat = 0;
	philo->dead = 0;
	if (!all->philos)
		all->philos = philo;
	else
		go_to_end(all, philo, NULL);
}

void create_philo_and_fork(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->rule->nbr_of_philo)
	{
		i++;
		create_philo(all, i);
		// mettre une sécu
		create_fork(all, i);
		// mettre une sécu
	}
	put_fork_on_table(all->philos, all->forks, all);
}

int pass_rules(char **argv, t_all *all)
{
	t_rules	*rule;

	rule = malloc(sizeof(t_rules));
	rule->nbr_of_philo = ft_atol(argv[1]);
	rule->time_to_die = ft_atol(argv[2]);
	rule->time_to_eat = ft_atol(argv[3]);
	rule->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		rule->nbr_to_eat = ft_atol(argv[5]);
	else
		rule->nbr_to_eat = -1;
	all->rule = rule;
	return (0);
}

int main(int argc, char **argv)
{
	t_all all;

	if (argc < 5 || argc > 6)
		return (0);
	if (argv[1] == NULL || ft_atol(argv[1]) == 0)
		return (0);
	all.forks = NULL;
	all.philos = NULL;
	all.rule = NULL;
	pass_rules(argv, &all);
	create_philo_and_fork(&all);
	if (!start_dinner(&all))
		return (write(2, "pb during dinner\n", 17), 1);
	// printf("philo n°%d\n", all.philos->id_philo);
	// printf("philo n°%d\n", all.philos->next->id_philo);
	// printf("fork n°%d\n", all.forks->id_fork);
	// printf("fork n°%d\n", all.forks->next->id_fork);

	// printf("%ld\n", all.rule->nbr_of_philo);
	// printf("%ld\n", all.rule->time_to_die);
	// printf("%ld\n", all.rule->time_to_eat);
	// printf("%ld\n", all.rule->time_to_sleep);
	// printf("%ld\n", all.rule->nbr_to_eat);
	free_all(&all);
	return (0);
}
