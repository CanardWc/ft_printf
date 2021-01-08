#include <libftprintf.h>

char	*ft_format_p(va_list ap)
{
	return (ft_itoa_mem(va_arg(ap, unsigned long int)));
}
