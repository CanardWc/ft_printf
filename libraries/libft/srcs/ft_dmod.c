#include <libft.h>

long double	ft_dmod(long double a, long double b)
{
	long double	mod;

	mod = a < 0 ? a * -1 : a;	
	if (b < 0)
		b = b * -1;
	while (mod >= b)
		mod = mod - b;
	return (a < 0 ? mod * -1 : mod);
}
