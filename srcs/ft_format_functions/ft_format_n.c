#include <libftprintf.h>

char	*ft_format_n(va_list ap, char *flags, int i)
{
	if (ft_strchr(flags, 'h') && *(ft_strchr(flags, 'h') + 1) == 'h')
		*(va_arg(ap, char *)) = i + 1;
	else if (ft_strchr(flags, 'h'))
		*(va_arg(ap, int *)) = i + 1;
	else if (ft_strchr(flags, 'l') && *(ft_strchr(flags, 'l') + 1) == 'l')
		*(va_arg(ap, long long int *)) = i + 1;
	else if (ft_strchr(flags, 'l'))
		*(va_arg(ap, long int *)) = i + 1;
	else
		*va_arg(ap, int *) = i + 1;
	return (NULL);
}
