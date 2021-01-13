#include <libftprintf.h>
t_string 	ft_format_size(int i, flags)
{
	t_string	ret;
	char		*tmp;
	int		nb;

	nb = i;	
	ret.size = 0;
	tmp = flags;
	flags = tmp;
	ret.size = i < 0 && atoi(strchr(flags, '0')) == ret.size ? ret.size++ : \
	ret.size;
	
	if(!(ret.str = ft_calloc(ret.size, sizeof(char)))
		return(0);
	return (ret);
}

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
