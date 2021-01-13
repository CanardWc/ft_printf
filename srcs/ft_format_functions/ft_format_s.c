#include <libftprintf.h>

char		*ft_format_s(va_list ap, char *flags)
{
	t_string	ret;
	int		prec;
	char		*s;
	int		i;
	
	s = va_arg(ap, char *);
	//ret = ft_format_size_s(s, flags);
	prec = ft_atoi(ft_strchr(flags, '.'));
	prec =  prec < 0 ? -1 : prec;
	i = 0;
	while (--prec > 0 && *s)
		ret.str[i++] = *s++;
	return (ret.str);
}
