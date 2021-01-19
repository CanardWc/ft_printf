#include <libftprintf.h>

t_string	ft_format_size_e(long double nb, char *flags)
{
	t_string	ret;
	int		prec;
	int		sign;
	int		nb_exposant;

	ret.size = 12;
	prec = 0;
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) + 6 : 12;
	sign = nb < 0 ? -1 : 1;
	nb *= sign;
	if (nb > 0)
	{
		while(nb = 10 && nb_exposant <= 110 )
		{
			nb /= 10;
			nb_exposant++;
		}
	}
	else if (nb < 0)
	{
		while(nb < 1 && nb_exposant <= 110)
		{
			nb *= 10
			nb_exposant++;
		}
	}
	prec = nb_exposant < 106 ? prec : prec++;
	if (ft_strchr(flags, '+') || ft_strchr(flags, ' ') || sign == -1)
		prec++;
	while (*flags)
		ret.size = ret.size < ft_atoi(flags) ? ft_atoi(flags++) : ret.size;
	ret.size = prec < ret.size ? ret.size : prec;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (0);
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
