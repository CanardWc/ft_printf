
#include "../includes/libft.h"

int	ft_nbrlen_octal(unsigned long long int nb)
{
	int len;

	len = 1;
	while (nb /= 8)
		len++;
	return (len);
}
