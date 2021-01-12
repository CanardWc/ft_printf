#include <libftprintf.h>

t_string	ft_format_p(va_list ap char *flags)
{
	char			*base = "0123456789abcdef";
	t_string		ret;
	int			size
	unsigned long int	i;
	
	i = va_arg(ap, unsigned long int);
	ret = ft_format_size(i, flags);
	size = ret.size - 1;
	while (i > 15)
	{
		ret.str[--size] = base[i % 16];
		i = i >> 4;
	}
	ret.str[--size] = base[i % 16];
	return (ret);
}
