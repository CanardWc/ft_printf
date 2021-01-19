#include <libftprintf.h>
#include <stdio.h>

t_string	ft_format_size_s(char *s, char *flags)
{
	t_string	ret;
	int		prec;

	ret.size = 0;
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) : 0;
	prec = prec > (int)ft_strlen(s) ? ft_strlen(s) : prec;
	ret.size = ft_strchr(flags, '-') ? \
		   ft_atoi(ft_strchr(flags, '-') + 1) : 0;
	ret.size = ret.size < prec ? prec + 1 : ret.size + 1;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret);
	return (ret);
}

char		*ft_format_s(va_list ap, char *flags, int i)
{
	t_string	ret;
	int		prec;
	char		*s;
	int		v;
	
	i = 0;
	s = va_arg(ap, char *);
	ret = ft_format_size_s(s, flags);
	prec = ft_atoi(ft_strchr(flags, '.'));
	prec =  prec < 0 ? -1 : prec;
	v = 0;
	while (--prec > 0 && *s)
		ret.str[v++] = *s++;
	return (ret.str);
}
