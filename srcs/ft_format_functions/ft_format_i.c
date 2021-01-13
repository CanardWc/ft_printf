#include <libftprintf.h>

t_string 	ft_format_size_i(int i, char *flags)
{
	t_string	ret;
	int		tmp;
	int 		sign;

	ret.size = 1;
	sign = i < 0 ? -1 : 1;
	i *= sign;
	tmp = 1;
	while ((nb /= 10) > 0)
		tmp++;
	if(strchr(flags, '+') || strchr(flags, ' ') || sign == -1)
		tmp++;
	while (*flags)
	{
		ret.size = ret.size < ft_atoi(flags) ? ft_atoi(flags) : ret.size;
		flags++;
	}
	ret.size = ret.size > tmp ? ret.size : tmp;
	if(!(ret.str = ft_calloc(ret.size + 1, sizeof(char))))
		return (0);
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

char			*ft_format_i(va_list ap, char *flags)
{
	t_string	ret;
	int		prec;
	int		size;
	long long int	i;

	i = ft_get_ap_i(ap, flags);
	ret = ft_format_size_i(i, flags);
	prec = ft_atoi(ft_strchr(flags, '.') + 1);
	size = ret.size - 1;
	prec =  prec < 0 ? -1 : prec;
	while (i > 9 )
	{
		ret.str[--size] = i % 10;
		i /= 10;
		prec--;
	}
	ret.str[--size] = i % 10;
	while (--prec > 0)
		ret.str[--size] = '0';
	ret.str[--size] = i < 0 ? '-' : ret.str[size];
	return (ret.str);
}
