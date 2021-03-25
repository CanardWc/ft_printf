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

int	main(void)
{
	t_dbl_data	dbl;
	unsigned long long	value;
	unsigned long long	base;
	unsigned long long	exp;
	double		d;
	int		i;

	i = 12;
	d = 4.0;
	base = 1;
	exp = 0;
	memcpy(&value, &d, sizeof(double));
	dbl.sign = value & 0x1 ? -1 : 1;
	while (--i > 0)
	{
		exp += ((value >> (63 - i)) & 1)  ? 1 * base : 0;
		base *= 2;
	}
	printf("exp = %llu\n", exp);
	return (0);
}
