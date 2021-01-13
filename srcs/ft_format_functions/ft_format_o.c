#include <libftprintf.h>

t_string	ft_format_size_o(int i, char *flags)
{
	t_string	ret;
	char		*tmp;

	tmp = flags;
	ret.size = 0;
	while ((nb /= 16) < 0)
		ret.size++;
	while (*flags)
		ret.size = ret.size < ft_atoi(flags) ? ft_atoi(flags++) : ret.size;
	if (ft_atoi(ft_strchr(tmp, '.') + 1 == ret.size))
		if (ft_strchr(tmp, '#'))
			ret.size += 1;
	ret.size++;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (0);
	return (ret);
}

unsigned long long int  ft_get_ap_o(va_list ap, char *flags)
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

char			*ft_format_o(va_list ap, char *flags)
{
	char			*base = "01234567";
	t_string		ret;
	int			prec;
	int			size;
	unsigned long long int	i;
	
	i = ft_get_ap_o(ap, flags);
	//ret = ft_format_size_o(i, flags);
	prec = ft_atoi(ft_strchr(flags, '.') + 1);
	size = ret.size - 1;
	prec = prec < 0 ? -1 : prec;
	while (i > 7)
	{
		ret.str[--size] = base[i % 8];
		i /= 8;
		prec--;
	}
	ret.str[--size] = base[i % 8];
	while (--prec > 0)
		ret.str[--size] = '0';
	return (ret.str);
}
