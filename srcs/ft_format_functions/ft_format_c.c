#include <libftprintf.h>

char	*ft_format_c(va_list ap, char *flags)
{
	char	c[2];

	c[0] = va_arg(ap, int);
	c[1] = 0;
	return (ft_strdup(c));
}
