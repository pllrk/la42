


#include "push_swap.h"

int verif_and_all(int argc, char *argv[])
{
    char    **a;

    if (argc < 2)
	{
        exit(0);
	}
	else if (argc == 2) // faire la verif de si il y a bien qqchose dans les ""
	{
		a = ft_split(argv[1], ' ');
		printf("dddd\n");
		verif_string(a);
	}
	else (verif_string(argv));
	{
		// a = push_into_a(argv);
		printf("ok\n");
	}
	return(1);
}