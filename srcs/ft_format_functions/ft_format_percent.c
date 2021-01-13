#include <libftprintf.h>

t_string	ft_format_size_p(int nb, char *flags)
{
	t_string	ret;
	char		*tmp;

	tmp = flags;
	ret.size = 0;
	while (*flags != ('.' && '%'))
		flags++;
	while (!ft_isidigt(flags) && *flags != '.' && *flags != '%')
		flags++;
	ret.size = ft_atoi(flags) > 0 ? ft_atoi(flags) + 1: 2;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (0);
	return (ret);
}

char	*ft_format_percent(va_list ap, char *flags)
{
	t_string	ret;

	ap = (void *)ap;
	flags = (void *)flags;
	//ret = ft_format_size_percent(flags);
	ret.str[0] = '%';
	return (ret.str);
}
