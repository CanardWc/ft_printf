
#include "../includes/libft.h"

int	ft_nbrlen_hexa(unsigned long long int nb)
{
	int len;

	len = 1;
	while (nb /= 16)
		len++;
	return (len);
}
