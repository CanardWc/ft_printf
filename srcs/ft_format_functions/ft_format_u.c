#include <libftprintf.h>

t_string 	ft_format_size_u(int i, char *flags)
{
	t_string	ret;
	int		tmp;

	ret.size = 1;
	tmp = 1;
	while ((i /= 10) > 0)
		tmp++;
	if(ft_strchr(flags, '+') || ft_strchr(flags, ' '))
		tmp++;
	while (*flags)
		ret.size = ret.size < ft_atoi(flags++) ? ft_atoi(flags - 1) : ret.size;
	ret.size = ret.size > tmp ? ret.size : tmp;
	if(!(ret.str = ft_calloc(ret.size + 1, sizeof(char))))
		return (ret);
	return (ret);
}

unsigned long long int	ft_get_ap_u(va_list ap, char *flags)
{
	if (ft_strchr(flags, 'l') && *(ft_strchr(flags, 'l') + 1) == 'l')
		return(va_arg(ap, unsigned long long int));
	else if (ft_strchr(flags, 'l'))
		return((unsigned long long int)va_arg(ap, unsigned long int));
	else if (ft_strchr(flags, 'h') && *(ft_strchr(flags, 'h') + 1) == 'h')
		return((unsigned long long int)va_arg(ap, unsigned int));
	else if (ft_strchr(flags, 'h'))
		return((unsigned long long int)va_arg(ap, unsigned int));
	else
		return((unsigned long long int)va_arg(ap, unsigned int));
}

char			*ft_format_u(va_list ap, char *flags, int i)
{
	t_string		ret;
	int			prec;
	int			size;
	unsigned long long int	v;
	
	i = 0;
	v = ft_get_ap_u(ap, flags);
	ret = ft_format_size_u(v, flags);
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) : 0;
	size = ret.size - 1;
	prec =  prec < 0 ? -1 : prec;
	while (v > 9)
	{
		ret.str[--size] = v % 10;
		v /= 10;
		prec--;
	}
	ret.str[--size] = v % 10;
	while (--prec > 0)
		ret.str[--size] = '0';
	return (ret.str);
}
