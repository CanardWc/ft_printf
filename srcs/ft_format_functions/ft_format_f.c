#include <libftprintf.h>

t_string	ft_format_size_f(long double nb, char *flags)
{
	t_string	ret;
	int			prec;
	int			sign;

	prec = 0;
	ret.size = 0;
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) + 2 : 8;
	sign = nb < 0 ? -1 : 1;
	nb *= sign;
	while ((nb /= 10.0) > 9)
		prec++;
	prec++;
	if (ft_strchr(flags, '+') || ft_strchr(flags, ' ') || sign == -1)
		prec++;
	while (*flags)
		ret.size = ret.size < ft_atoi(flags++) ? ft_atoi(flags - 1) : ret.size;
	ret.size = prec < ret.size ? ret.size + 1 : prec + 1;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret);
	return (ret);
}
long double	ft_get_ap_f(va_list ap, char *flags)
{
	if (ft_strchr(flags, 'l'))
		return((long double)va_arg(ap, long double));
	else
		return((long double)va_arg(ap, double));
}

char	*ft_format_f(va_list ap, char *flags, int i)
{
	t_string	ret;
	long double	prec;
	long double	size;
	long double	v;

	i = 0;
	v = ft_get_ap_f(ap, flags);
	//ret = ft_format_size_f(v flags);
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) : 6;
	size = (long double)(ret.size - 1);
	if (prec > 0)
		ret.str[(int)(size-- - prec)] = '.';
	while (prec > 0)
		ret.str[(int)size--] = ft_dmod((v * (10 * prec--)), 10) + '0';
	while (i > 10)
	{
		ret.str[(int)--size] = ft_dmod(v, 10) + '0';
		v /= 10;
	}
	ret.str[(int)--size] = ft_dmod(v, 10) + '0';
	return (ret.str);
}
