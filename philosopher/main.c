#include "philo.h"



void pass_rules(char **argv, t_rules *rule)
{
	rule->nbr_of_philo = ft_atoi(argv[1]);
	rule->time_to_die = ft_atoi(argv[2]);
	rule->time_to_eat = ft_atoi(argv[3]);
	rule->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rule->nbr_to_eat = ft_atoi(argv[5]);
	else
		rule->nbr_to_eat = -1;
}

int main(int argc, char **argv)
{
	t_rules rule;

	int i = 0;
	while (argv[i])
	{
		printf("%d : %s\n", i, argv[i]);
		i++;
	}
	if (argc < 5 || argc > 6)
		return (0);
	pass_rules(argv, &rule);

	return (0);
}
