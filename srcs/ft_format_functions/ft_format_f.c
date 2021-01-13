#include <libftprintf.h>

t_string	ft_format_size_f(long double nb, char *flags)
{
	t_string	ret;
	int			prec;
	int			sign;

	prec = 0;
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) + 2 : 8;
	sign = nb < 0 ? -1 : 1;
	nb *= sign;
	while ((nb /= 10) > 9)
		prec++;
	prec++;
	if (ft_strchr(flags, '+') || ft_strchr(flags, ' ') || sign == -1)
		prec++;
	while (*flags)
		ret.size = ret.size < ft_atoi(flags) ? ft_atoi(flags++) : ret.size;
	ret.size = prec < ret.size ? ret.size : prec;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (0);
	return (ret);
}
