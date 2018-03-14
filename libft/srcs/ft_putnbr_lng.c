
#include "../includes/libft.h"

void	ft_putnbr_lng(long long int n)
{
	if (n <= LONG_MIN)
	{
		ft_putstr("-9223372036854775808");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr_lng(n / 10);
	ft_putchar(n % 10 + '0');
}
