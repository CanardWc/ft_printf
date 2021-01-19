#include <libftprintf.h>

t_string	ft_format_size_c(char *flags)
{
	t_string	ret;

	ret.size = ft_strchr(flags, '-') ? \
			   ft_atoi(ft_strchr(flags, '-') + 1) + 1 : 2;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret);
	return (ret);
}

char	*ft_format_c(va_list ap, char *flags, int i)
{
	t_string	ret;

	i = 0;
	ret = ft_format_size_c(flags);
	flags = (void *)flags;
	ret.str[0] = (unsigned char)va_arg(ap, int);
	return (ret.str);
}
