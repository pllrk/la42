
#include "push_swap.h"

int	no_double(char *argv[])
{
	int	i;
	int	j;
	int	y;

	i = 0;
	j = 1;
	y = 0;
	while (argv[i] != NULL)
    {
		j = i + 1;
		y = ft_atoi(argv[i]);
        while (argv[j] != NULL)
		{
			if (y != ft_atoi(argv[j]))
				j++;
			else
			{
				ft_fprintf(stderr, "erreur dans double");
				exit(1);
			}
		}
		i++;		
    }
    return (1);
}

int	no_big(char *argv[])
{
	int i;

    i = 0;
	while (argv[i] != NULL)
    {
		if ((push_atol(argv[i]) > INT_MAX) || (push_atol(argv[i]) < INT_MIN))
		{
			printf("erreur dans big");
			exit(1);
		}
		i++;
	}
	return (1);
}

int no_char(char *argv[])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[i] != NULL)
    {
        while (argv[i][j] != '\0')
        {  
			if (((argv[i][j] == '-') || (argv[i][j] == '+')) )
				j++;
            if (!ft_isdigit(argv[i][j])) 
			{
                printf("erreur dans char");
                exit(1);
			}
			j++;
        }
        i++;
        j = 0;
    }
    return (1);
}

int verif_string(char *argv[])
{
    int i;

    i = 0;
    if ((no_char(argv) == 1) && (no_big(argv) == 1) && (no_double(argv) == 1))
       	return (1);
    // if (no_big(argv) == 1)
	//     i++;
	// if (no_double(argv) == 1)
	// 	i++;
	else
    	return (0);
}