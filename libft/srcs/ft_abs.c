
#include "../includes/libft.h"

int	ft_abs(int nb)
{
	long long int nbr;

	nbr = nb;
	return (nbr < 0 ? -nbr : nbr);
}
