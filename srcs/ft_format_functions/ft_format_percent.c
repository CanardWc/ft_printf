#include <libftprintf.h>

char	*ft_format_percent(va_list ap)
{
	ap = (void *)ap;
	return (ft_strdup("%"));
}
