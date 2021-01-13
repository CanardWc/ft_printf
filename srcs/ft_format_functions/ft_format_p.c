#include <libftprintf.h>

t_string	ft_format_size_p(int nb, char *flags)
{
	t_string		ret;
	int				i;

	ret.size = 0;
	i = 1;
	while ((nb = nb >> 4)  > 0)
		i++;
	ret.size = ft_strchr(flags, '-') ? \
			   ft_atoi(ft_strchr(flags, '-') + 1) + 1 : 0;
	ret.size = ret.size < i ? i : ret.size;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (0);
	return (ret);
}

char	*ft_format_p(va_list ap, char *flags)
{
	char			*base = "0123456789abcdef";
	t_string		ret;
	int			size;
	unsigned long int	i;
	
	i = va_arg(ap, unsigned long int);
	flags = (void *)flags;
	//ret = ft_format_size_p(i, flags);
	size = ret.size - 1;
	while (i > 15)
	{
		ret.str[--size] = base[i % 16];
		i = i >> 4;
	}
	ret.str[--size] = base[i % 16];
	return (ret.str);
}
