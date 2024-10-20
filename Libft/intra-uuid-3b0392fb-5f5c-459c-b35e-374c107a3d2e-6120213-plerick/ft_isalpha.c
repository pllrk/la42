

#include "libft.h"

int	ft_is_alpha(int c)
{
	if (c < 64 || (c > 90 && c < 97 || c > 123)
		return(0);
	return (1);
}
