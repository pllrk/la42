

#include "libft.h"

int	ft_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 64 || (str[i] > 90 && str[i] < 97 || str[i] > 123)
		{
			return(0);
		}
		i++;
	}
	return (1);
}
