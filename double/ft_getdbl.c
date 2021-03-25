#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef union			s_dbl_pars
{
	unsigned long long	sign : 1;
	int			exp : 11;
	unsigned long long	fract : 52;
}				t_dbl_pars;

typedef struct			s_dlb_data
{
	int	sign;
	char	*decimal;
	int	pow;
}				t_dbl_data;

t_dbl_data	ft_getdbl_exponent(t_dbl_data ret, t_dbl_pars dbl);
char		*ft_getdbl_fraction(t_dbl_pars dbl);

t_dbl_data	ft_get_double(double d)
{
	t_dbl_pars	parsed_dbl;
	t_dbl_data	dbl;
	int		exp;
	int		i;

	i = 0;
	memcpy(&parsed_dbl, &d, sizeof(double));
	dbl.sign = parsed_dbl.sign == 0 ? 1 : -1;
	printf("exp : %d\n", parsed_dbl.exp);
	printf("fraction : %d\n", parsed_dbl.exp);
	exp = parsed_dbl.exp - 1023;
	dbl.decimal = ft_getdbl_fraction(parsed_dbl);
	dbl = ft_getdbl_exponent(dbl, parsed_dbl);
	return (dbl);
}

int	main(void)
{
	double		d;
	t_dbl_data	dbl;

	d = 4.0;
	dbl = ft_get_double(d);
	printf("sign : %c\n", dbl.sign == -1 ? '-' : ' ');
	printf("decimal : %s\n", dbl.decimal);
	printf("pow : %d\n", dbl.pow);
	return (0);
}
