#include <libftprintf.h>

char	*ft_format_percent(va_list ap, char *flags)
{
	t_string	ret;

	ap = (void *)ap;
	flags = (void *)flags;
	//ret = ft_format_size_percent(flags);
	ret.str[0] = '%';
	return (ret.str);
}
