#include <libftprintf.h>

char	*ft_format_x(va_list ap, char *flags)
{
	return (ft_itoa_base(va_arg(ap, unsigned int), "0123456789abcdef"));
}
