#include <libftprintf.h>

t_string 	ft_format_size_i(int i, char *flags)
{
	t_string	ret;
	int	tmp;
	int 	sign;
	char	*t_flags;

	t_flags = flags;
	ret.size = 1;
	sign = i < 0 ? -1 : 1;
	i *= sign;
	tmp = 1;
	while ((i /= 10) > 0)
		tmp++;
	while (*flags && *flags != '.')
		ret.size = ret.size < ft_atoi(flags++) ? ft_atoi(flags - 1) : ret.size;
	if (ft_strchr(flags, '.'))
		tmp = ft_atoi(ft_strchr(flags, '.') + 1) > tmp ? \
			  ft_atoi(ft_strchr(flags, '.') + 1) : tmp;
	if (ft_strchr(t_flags, '+') || ft_strchr(t_flags, ' ') || sign == -1)
		tmp++;
	ret.size = ret.size > tmp ? ret.size + 1 : tmp + 1;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret);
	return (ret);
}


unsigned long long int	ft_get_ap_i(va_list ap, char *flags)
{
	if (ft_strchr(flags, 'l') && *(ft_strchr(flags, 'l') + 1) == 'l')
		return(va_arg(ap, long long int));
	else if (ft_strchr(flags, 'l'))
		return((long long int)va_arg(ap, long int));
	else if (ft_strchr(flags, 'h') && *(ft_strchr(flags, 'h') + 1))
		return((long long int)va_arg(ap, int));
	else if (ft_strchr(flags, 'h'))
		return((long long int)va_arg(ap, int));
	else
		return((long long int)va_arg(ap, int));
}

char			*ft_format_i(va_list ap, char *flags, int i)
{
	t_string	ret;
	int		prec;
	int		size;
	long long int	v;
	
	i = 0;
	v = ft_get_ap_i(ap, flags);
	ret = ft_format_size_i(v, flags);
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) : 0;
	size = ret.size - 1;
	prec =  prec < 0 ? -1 : prec;
	while (v > 9 || v < -9)
	{
		ret.str[--size] = v < 0 ? (v * -1) % 10 + '0' : v % 10 + '0';
		v = v / 10;
		prec--;
	}
	ret.str[--size] = v < 0 ? (v * -1) % 10 + '0' : v % 10 + '0';;
	while (--prec > 0)
		ret.str[--size] = '0';
	ret.str[--size] = v < 0 ? '-' : ret.str[size];
	return (ret.str);
}
