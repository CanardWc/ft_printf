#include "stdio.h"
#include "assert.h"

int	ft_ulllen(unsigned long long value)
{
	int	i;

	i = 1;
	while ((value /= 10) > 0)
		i++;
	return (i);
}

char	*treat_value(char *ret, int exp)
{
	char	*save;
	int	act;
	int	tmp;
	int	i;

	i = 0;
	tmp = 0;
	if (exp < 0)
	{
		exp = exp < 0 ? exp * -1 : exp;
		while (exp > 0)
		{
			save = ret;
			while (*save || tmp)
			{
		//	printf("coucou tmp %d\n", tmp);
				if (!*save)
					*save = 48;
				act = ((*save - 48) * 10) / 2;
		//		printf("act = %d\n", act);
		//		printf("*save = %c\n", *save);
				*save++ = (act / 10 + tmp) + 48;
		//		printf("*save1 = %c\n", *save);
				tmp = act % 10;
				if (tmp == -5)
					exit(0);
			}
			exp--;
		}
	}
	else
	{
		while (exp > 0)
		{
			i = 329;
			while ((ret[i] || tmp) && i > 0)
			{
				if (!ret[i])
					ret[i] = 48;
				act = (ret[i] - 48) * 2;
				ret[i--] = (act % 10 + tmp) + 48;
				tmp = act / 10;
			}
			exp--;
		}
	}
	return (ret);
}

char	*stock_value(unsigned long long value, int exp)
{
	char			*ret;
	int			i;
	int			len;
	int			tmp;

	if (value == 0)
		return (NULL);
	tmp = 0;
	len = ft_ulllen(value);
	i = 339;
	ret = (char *)malloc(sizeof(char) * (340));
	bzero(ret, 310);
	value *= 10;
	if (exp <= 0)
		while ((value /= 10) > 0)
			ret[--len] = (int)(value % 10 + '0');
	else
		while ((value /= 10) > 0)
			ret[i--] = (int)(value % 10 + '0');
	return (ret);
}

void print_raw_double_binary(double d)
{
	unsigned long long int	*double_as_int;
	int			core_nbr;
	int			exp;
	unsigned long long int	value;
	int			exp_value;
	int 			i;
	unsigned long long int	base;
	unsigned long long int	tmp;

	double_as_int = (unsigned long long *)&d;
	i = 0;
	if ((*double_as_int >> (63 - i)) & 1)
		putchar('-');
	printf(" ");
	i = 12;
	base = 1;
	exp = 0;
	while (--i > 0)
	{
		tmp = ((*double_as_int >> (63 - i)) & 1) ? 1 : 0;
		exp += tmp * base;
		base *= 2;
	}
	i = 11;
	exp_value = 0;
	while (++i < 64)
		if ((*double_as_int >> i) & 1)
			exp_value = i - 11;
	printf("first exp = %d\n", exp);
	printf("first exp_value = %d\n", exp_value);
	exp -= (1023 + exp_value);
	printf("exp = %d", exp);
	printf(" ");
	value = *double_as_int & 0x001FFFFFFFFFFFFFULL;
	printf("value = %llu\n", value);
	
	char *ret = stock_value(value, exp);
	printf("ret = %s\n", ret);
	if (ret)
		ret = treat_value(ret, exp);
	if (ret != NULL)
		while (!(*ret))
			ret++;
	printf("ret = %s\n", ret);
}

void parse_double(double d, unsigned char *sign_field, unsigned short *exponent_field, \
		unsigned long long *fraction_field)
{
	unsigned long long *double_as_int = (unsigned long long *)&d;

	*sign_field = (unsigned char)(*double_as_int >> 63);
	*exponent_field = (unsigned short)(*double_as_int >> 52 & 0x7FF);
	*fraction_field = *double_as_int & 0x000FFFFFFFFFFFFFULL;
}

void print_raw_double_hex(double d)
{
	unsigned char sign_field;
	unsigned short exponent_field;
	unsigned long long fraction_field;

	parse_double(d, &sign_field, &exponent_field, &fraction_field);

	printf("%u %u %llu\n", sign_field, exponent_field, fraction_field);
}

int main(int argc, char *argv[])
{
	double d;
	int i;

	/* Make sure unsigned long long is 8 bytes */
	assert (sizeof(unsigned long long) == sizeof(double));

	d = 0.5;
	printf("0.5:\n");
	printf("double = %g\n", d);
	printf("%a\n", d);
	print_raw_double_binary(d);
	print_raw_double_hex(d);
	printf("\n");

	d = 0.1;
	printf("0.1:\n");
	printf("double = %g\n", d);
	print_raw_double_binary(d);
	print_raw_double_hex(d);
	printf("\n");

	/* d = NaN */
	printf("NaN:\n");
	d = 0;
	d/=d;
	printf("double = %g\n", d);
	print_raw_double_binary(d);
	print_raw_double_hex(d);
	printf("\n");

	/* d = +infinity */
	printf("+infinity:\n");
	d = 1e300;
	d*=d;
	printf("double = %g\n", d);
	print_raw_double_binary(d);
	print_raw_double_hex(d);
	printf("\n");

	/* d = 2^-1074 */
	printf("2^-1074:\n");
	d = 1;
	for (i=1; i<=1074; i++)
		d/=2;
	printf("double = %g\n", d);
	print_raw_double_binary(d);
	print_raw_double_hex(d);
	printf("\n");

	/* d = 1/3 */
	printf("1/3:\n");
	d = 1.0/3.0;
	printf("double = %g\n", d);
	print_raw_double_binary(d);
	print_raw_double_hex(d);

	return (0);
}
