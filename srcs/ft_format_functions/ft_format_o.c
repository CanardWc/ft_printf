#include <libftprintf.h>

char	*ft_format_o(va_list ap, char * flags)
{
	return (ft_itoa_base(va_arg(ap, unsigned int), "01234567"));
}
