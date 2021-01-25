#include <libftprintf.h>

long double	ft_get_ap_g(va_list ap, char *flags)
{
	if (ft_strchr(flags, 'l'))
		return((long double)va_arg(ap, long double));
	else
		return((long double)va_arg(ap, double));
}

int		ft_get_pow(long double v)
{
	int	pow;

	pow = 0;
	v = v < 0 ? v * -1 : v;
	if (v == 0)
		return (pow);
	if ((int)v > 0)
		while ((v /= 10) > 9)
			pow++;
	else
		while ((int)(v *= 10) == 0)
			pow--;
	return (pow);
}

char	*ft_format_g(va_list ap, char *flags, int i)
{
	t_string	ret;
	long double	prec;
	long double	v;
	int		size;
	int		pow;

	i = 0;
	v = ft_get_ap_e(v, flags);
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) : 6;
	ret = ft_format_size_e(v, flags);
	size = ret.size - 1;
	pow = ft_get_pow(v);
	v = pow == 0 ? v : v * (10 * pow);
	while (pow > 9 || (pow /= 10) < 9)
		ret.str[--size] = pow % 10 + '0';
	ret.str[--size] = pow % 10 + '0';
	ret.str[--size] = pow < 0 ? '-' : ret.str[size];
	ret.str[pow < 0 ? --size : size] = 'e';
	v = prec > 0 ? v * (10 * prec) : v;	
	while ((v /= 10) > 9)
		ret.str[--size] = v % 10 + '0';
	if (prec > 0)
		ret.str[--size] = '.';
