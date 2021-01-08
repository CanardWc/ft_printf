#include <libftprintf.h>

char	*ft_format_s(va_list ap)
{
	return (ft_strdup(va_arg(ap, char *)));
}
