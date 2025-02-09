

#include "push_swap.h"

// int	no_double(char *argv[])
// {
// 	int	i;

// 	i = 0;

// }

int	no_big(char *argv[])
{
	int i;

    i = 0;
	while (argv[i] != NULL)
    {
		if ((push_atol(argv[i]) > INT_MAX) || (push_atol(argv[i]) < INT_MIN))
		{
			write(1,"blo\n", 4);
			exit(0);
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
        while (*argv[j] != '\0')
        {  
            if (ft_isdigit(*argv[j]) && ((*argv[j] != '-') || (*argv[j] != '+')))
            {
                write(1, "bla\n", 4);
                exit(0);
            }
            j++;
        }
        i++;
        j = 0;
    }
    return (1);
}

int nosplit(char *argv[])
{
    int i;

    i = 0; 
    if (no_char(argv) == 1)
        i++;
    if (no_big(argv) == 1)
	{
	    i++;
	}
		// if (no_double(argv) == 1)
	// 	i++;
	return (1);
}