#include <libftprintf.h>

#include <stdio.h>

t_dbl	ft_getdbl(double d)
{
	t_dbl			dbl;
	unsigned long long	parsed_dbl;
	int			exp;
	int			base;
	int			i;

	i = 12;
	exp = 0;
	base = 1;
	ft_memcpy(&parsed_dbl, &d, sizeof(double));
	dbl.sign = (parsed_dbl >> 63) & 1 ? -1 : 1;
	while (--i > 0)
	{
		exp += (parsed_dbl >> (63 - i) & 1) ? 1 * base : 0;
		base *= 2;
	}
	// if exp = 2047 it's infinity
	// if exp = 2047 and there's 1 bite in the fraction then it's nan
	if (exp == 0)
		exp++;
	exp -= 1023;
	dbl.decimal = ft_getdbl_fraction(parsed_dbl, exp);
	//printf("ret = %s\n", dbl.decimal);
	dbl = ft_getdbl_exponent(dbl, exp);
	//printf("ret = %s\n", dbl.decimal);
	return (dbl);
}
