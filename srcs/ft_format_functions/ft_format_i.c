#include <libftprintf.h>

char	*ft_format_i(va_list ap)
{
	return (ft_itoa(va_arg(ap, int)));
}
