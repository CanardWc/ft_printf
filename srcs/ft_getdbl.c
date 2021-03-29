#include <libftprintf.h>

t_dbl	ft_getdbl(double d)
{
	t_dbl			dbl;
	unsigned long long	parsed_dbl;
	int			exp;
	int			base;
	int			i;

	i = 12;
	exp = -1023;
	base = 1;
	ft_memcpy(&parsed_dbl, &d, sizeof(double));
	dbl.sign = (parsed_dbl >> 63) & 1 ? -1 : 1;
	while (--i > 0)
	{
		exp += (parsed_dbl >> (63 - i) & 1) ? 1 * base : 0;
		base *= 2;
	}
	exp = exp == -1023 ? 0 : exp;
	dbl.decimal = ft_getdbl_fraction(parsed_dbl, exp);
	//ft_putnbr_fd(exp, 1);
	//write(1, "\n", 1);
	//ft_putstr_fd(dbl.decimal, 1);
	//write(1, "\n", 1);
	dbl = ft_getdbl_exponent(dbl, exp);
	return (dbl);
}
