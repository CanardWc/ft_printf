#include <libftprintf.h>

char	*ft_format_percent(va_list ap, char *flags)
{
	t_string	ret;

	ap = (void *)ap;
	ret = ft_format_size(flags);
	c[0] = '%';
	return (ret);
}
