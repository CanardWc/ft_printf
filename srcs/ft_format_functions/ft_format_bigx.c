#include <libftprintf.h>

t_string	ft_format_bigx(va_list ap, char *flags)
{
	char		*base = "0123456789ABCDEF";
	t_string	ret;
	int		prec;
	int		size
	unsigned int	i;
	
	i = va_arg(ap, unsigned int);
	ret = ft_format_size(i, flags);
	prec = ft_atoi(ft_strchr(flags, '.'));
	size = ret.size - 1;
	prec =  prec > 0 ? prec : -1;
	while (i > 15)
	{
		ret.str[--size] = base[i % 16];
		i /= 16;
		prec--;
	}
	ret.str[--size] = base[i % 16];
	while (--prec > 0)
		ret.str[--size] = '0';
	return (ret);
}
