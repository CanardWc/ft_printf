#include <libftprintf.h>

t_string	ft_format_size(char *flags)
{
	t_string	ret;

	ret.size = ft_strchr(flags, '-') ? \
			   ft_atoi(ft_strchr(flags, '-') + 1) + 1 : 2;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (0);
	return (ret)
}

char	*ft_format_c(va_list ap, char *flags)
{
	t_string	ret;

	//ret = ft_format_size_c(flags);
	flags = (void *)flags;
	ret.str[0] = (unsigned char)va_arg(ap, int);
	return (ret.str);
}
