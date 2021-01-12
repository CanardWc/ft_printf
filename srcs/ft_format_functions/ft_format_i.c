#include <libftprintf.h>

t_string	ft_format_i(va_list ap, char *flags)
{
	t_string	ret;
	int		prec;
	int		size
	int		i;
	
	i = va_arg(ap, int);
	ret = ft_format_size(i, flags);
	prec = 0;
	if (ft_strchr(flags, '.'))
		prec = ft_strchr(flags, '.') + 1 == '*' ? va_arg(ap, int) : \
		       ft_atoi(ft_strchr(flags, '.'));
	size = ret.size - 1;
	prec =  prec > 0 ? prec : -1;
	while (i > 9 && (prec || !prec--))
	{
		ret.str[--size] = i % 10;
		i /= 10;
	}
	ret.str[--size] = i % 10;
	ret.str[--size] = i < 0 ? '-' : ret.str[size];
	while (--prec > 0)
		ret.str[--size] = '0';
	return (ret);
}
