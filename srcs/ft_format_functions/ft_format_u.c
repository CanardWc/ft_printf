#include <libftprintf.h>

char	*ft_format_u(va_list ap, char *flags)
{
	return (ft_itoa(va_arg(ap, unsigned int)));
}
