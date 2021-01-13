#include <libftprintf.h>

unsigned long long int	ft_get_ap_bigx(va_list ap, char *flags)
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

char	*ft_format_bigx(va_list ap, char *flags)
{
	char			*base = "0123456789ABCDEF";
	t_string		ret;
	int			prec;
	int			size;
	unsigned long long int	i;
	
	i = ft_get_ap_bigx(ap, flags);
	//ret = ft_format_size_bigx(i, flags);
	prec = ft_atoi(ft_strchr(flags, '.') + 1);
	size = ret.size - 1;
	prec =  prec < 0 ? -1 : prec;
	while (i > 15)
	{
		ret.str[--size] = base[i % 16];
		i /= 16;
		prec--;
	}
	ret.str[--size] = base[i % 16];
	while (--prec > 0)
		ret.str[--size] = '0';
	return (ret.str);
}
