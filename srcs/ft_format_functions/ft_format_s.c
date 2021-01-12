#include <libftprintf.h>

t_string	ft_format_s(va_list ap, char *flags)
{
	t_string	ret;
	int		prec;
	char		s;
	int		i;
	
	s = va_arg(ap, char *);
	ret = ft_format_size(s, flags);
	prec = 0;
	if (ft_strchr(flags, '.'))
		prec = ft_strchr(flags, '.') + 1 == '*' ? va_arg(ap, int) : \
		       ft_atoi(ft_strchr(flags, '.'));
	prec =  prec > 0 ? prec : -1;
	i = 0;
	while (--prec > 0 && *s)
		ret.str[i++] = *s++;
	return (ret);
}
