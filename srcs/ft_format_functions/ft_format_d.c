#include <libftprintf.h>

char	*ft_format_d(va_list ap)
{
	return (ft_itoa(va_arg(ap, int)));
}
