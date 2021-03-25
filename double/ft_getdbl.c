#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct			s_dlb_data
{
	int	sign;
	char	*decimal;
	int	pow;
}				t_dbl_data;

t_dbl_data	ft_getdbl_exponent(t_dbl_data ret, int exp);
char		*ft_getdbl_fraction(unsigned long long parsed_dbl, int exp);

t_dbl_data	ft_get_double(double d)
{
	t_dbl_data		dbl;
	unsigned long long	parsed_dbl;
	int			exp;
	int			base;
	int			i;

	i = 12;
	exp = -1023;
	base = 1;
	memcpy(&parsed_dbl, &d, sizeof(double));
	dbl.sign = parsed_dbl & 1 ? -1 : 1;
	while (--i > 0)
	{
		exp += (parsed_dbl >> (63 - i) & 1) ? 1 * base : 0;
		base *= 2;
	}
	printf("exp : %d\n", exp);
	dbl.decimal = ft_getdbl_fraction(parsed_dbl, exp);
//	while (!dbl.decimal)
//		dbl.decimal++;
	printf("fraction : %s\n", dbl.decimal);
	dbl = ft_getdbl_exponent(dbl, exp);
	return (dbl);
}

int	main(void)
{
	double		d;
	t_dbl_data	dbl;

	d = 0.00000000009999123912999999;
	dbl = ft_get_double(d);
	printf("sign : %c\n", dbl.sign == -1 ? '-' : ' ');
	printf("decimal : %s\n", dbl.decimal);
	printf("pow : %d\n", dbl.pow);
	printf("double : %e\n", d);
	return (0);
}
