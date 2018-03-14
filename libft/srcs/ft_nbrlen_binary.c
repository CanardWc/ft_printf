
#include "../includes/libft.h"

int	ft_nbrlen_binary(unsigned long long int nb)
{
	int len;

	len = 1;
	while (nb /= 2)
		len++;
	return (len);
}
