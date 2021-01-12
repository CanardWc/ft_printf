#include <libftprintf.h>

t_string	ft_format_o(va_list ap, char * flags)
{
	char		*base = "01234567";
	t_string	ret;
	int		prec;
	int		size
	unsigned int	i;
	
	i = va_arg(ap, unsigned int);
	ret = ft_format_size(i, flags);
	prec = 0;
	if (ft_strchr(flags, '.'))
		prec = ft_strchr(flags, '.') + 1 == '*' ? va_arg(ap, int) : \
		       ft_atoi(ft_strchr(flags, '.'));
	size = ret.size - 1;
	if (prec <= 0)
		prec == -1;
	while (i > 7)
	{
		ret.str[--size] = base[i % 8];
		i /= 8;
		prec--;
	}
	ret.str[--size] = base[i % 8];
	while (--prec > 0)
		ret.str[--size] = '0';
	return (ret);
}
