#include <libftprintf.h>

char	*ft_format_bigx(va_list ap)
{
	return (ft_itoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
}
