#include <libftprintf.h>

t_string	ft_format_size_s(char *s, char *flags)
{
	t_string	ret;
	int			prec;

	ret.size = 0;
	prec = 0;
	if (ft_strchr(flags, '.'))
		prec = ft_atoi(ft_strchr(flags, '.') + 1);
	prec = prec > ft_strlen(s) ? ft_strlen(s) : prec;
	ret.size = ft_atoi(ft_strchr(flags, '-') + 1);
	ret.size = ret.size < prec ? prec + 1 : ret.size + 1;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (0);
	return (ret);
}

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
