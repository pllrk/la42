#include "philo.h"

long get_time_begin(void)
{
	struct	timeval start;
	long	time_begin;

	gettimeofday(&start, NULL);
	time_begin = (start.tv_sec * 1000 + start.tv_usec / 1000);
	return (time_begin);
}

long	ft_atol(const char *str)
{
	int	i;
	long	neg;
	long	chif;

	i = 0;
	neg = 1;
	chif = 0;
	if (*str == '\0')
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg = neg * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		chif = chif * 10 + (str[i] - '0');
		i++;
	}
	return (chif * neg);
}
