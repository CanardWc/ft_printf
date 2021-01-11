#include <libftprintf.h>

char	*ft_format_percent(va_list ap, char *flags)
{
	ap = (void *)ap;
	return (ft_strdup("%"));
}
