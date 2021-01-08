#include <libftprintf.h>

char	*ft_format_u(va_list ap)
{
	return (ft_itoa(va_arg(ap, unsigned int)));
}
