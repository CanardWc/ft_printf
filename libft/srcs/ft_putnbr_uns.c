
#include "../includes/libft.h"

void	ft_putnbr_uns(unsigned long long int n)
{
	if (n >= 10)
	{
		ft_putnbr_uns(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar((n % 10) + '0');
}
