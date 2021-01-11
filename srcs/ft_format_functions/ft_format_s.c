#include <libftprintf.h>

char	*ft_format_s(va_list ap, char *flags)
{
	return (ft_strdup(va_arg(ap, char *)));
}
