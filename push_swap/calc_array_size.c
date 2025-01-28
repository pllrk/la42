

#include "push_swap.h"

int	calc_array_size(char *argv)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;

	while (argv[i] == ' ')
		i++;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) == 1)
			count++;
		while (argv[i] != ' ' && argv[i] != '\0')
			i++;
		if (argv[i] == '\0')
			return (count);
		i++;
	}
	return(count);
	// Calculer la taille de l'array à partir du nombre de virgule ou d'espace, il faut voir par rapport au sujet
}