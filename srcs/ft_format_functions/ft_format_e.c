#include <libftprintf.h>

int ft_get_pow(long double fl)
{
	int pow;
	pow = 0;
	if (fl < 1)
		while((int)fl == 0)
		{
			fl *= 10.0;
			pow--;
		}
	else if (fl > 1)
		while((long long int)fl > 9)
		{
			fl /= 10.0;
			pow++;
		}
	return(pow);
}
int		ft_format_size_e(long double nb, char *flags)
{
	t_string	ret;
	int			prec;
	int			sign;
	int			pow;
	ret = 0;
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) + 6 : 12;
	sign = nb < 0 ? -1 : 1;
	nb *= sign;
	pow = ft_get_pow(nb);
	prec = pow < 99 ? prec : prec++;
	if (ft_strchr(flags, '+') || ft_strchr(flags, ' ') || sign == -1)
		prec++;
	while (*flags && *flags != '.')
		ret.size = ret.size < ft_atoi(flags++) ? ft_atoi(flags - 1) : ret.size;
	ret.size = prec < ret.size && ret.size != 0 ? ret.size + 1 : prec + 1;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret.size);
	return (ret);
}

long double	ft_get_ap_e(va_list ap, char *flags)
{
	if (ft_strchr(flags, 'l'))
		return((long double)va_arg(ap, long double));
	else
		return((long double)va_arg(ap, double));
}

char	*ft_format_e(va_list ap, char *flags, int i)
{
	t_string	ret;
	long double	prec;
	long double	size;
	long double	v;

	i = 0;
	v = ft_get_ap_e(ap, flags);
	//ret = ft_format_size_e(v flags);
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

char	*ft_format_e(va_list ap, char *flags, int i)
{
	t_string	ret;
	long double	prec;
	long double	size;
	long double	v;
	long double	pow;

	i = 0;
	v = ft_get_ap_e(v, flags);
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) : 6;
	ret = ft_format_size_e(v, flags);
	size = (long double)(ret.size - 1);
	pow = 0;
	if (prec > 0)
		ret.str[(int)(size-- - prec)] = '.';
	if (v > 0)
		while (v / (10 * pow) > 9)
			pow++;
	else
		while (v * (10 * pow) <= 0)
			pow++;
	pow = prec > 0 ? pow - prec : pow;
	
}
