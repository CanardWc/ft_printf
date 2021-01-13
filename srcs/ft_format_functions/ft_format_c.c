#include <libftprintf.h>

t_string	ft_format_c(va_list ap, char *flags)
{
	t_string	ret;

	ret = ft_format_size(flags);
	ret.str[0] = (unsigned char)va_arg(ap, int);
	return (ret);
}
