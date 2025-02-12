

#include "push_swap.h"

int	verif_and_all(int argc, char *argv[])
{
	char **a;

	if (argc < 2)
	{
		exit(0);
	}
	else if (argc == 2)
	{
		if (argv[1][0] == '\0')
			exit(0);
		a = ft_split(argv[1], ' ');
		if (verif_string(a))
			fprintf(stderr , "Error\n");
	}
	else
		(verif_string(argv + 1));
	{
		// a = push_into_a(argv);
		printf("ok\n");
	}
	return (1);
}