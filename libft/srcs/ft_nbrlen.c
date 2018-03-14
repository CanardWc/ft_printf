
#include "../includes/libft.h"

int	ft_nbrlen(long long int nb)
{
	int len;

	if (nb <= LONG_MIN)
		return (20);
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
