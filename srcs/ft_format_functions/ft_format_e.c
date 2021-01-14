#include <libftprintf.h>

t_string	ft_format_size_e(long double nb, char *flags)
{
	t_string	ret;
	int		prec;
	int		sign;
	int		nb_exposant;

	ret.size = 12;
	prec = 0;
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) + 6 : 12;
	sign = nb < 0 ? -1 : 1;
	nb *= sign;
	if (nb > 0)
	{
		while(nb = 10 && nb_exposant <= 110 )
		{
			nb /= 10;
			nb_exposant++;
		}
	}
	else if (nb < 0)
	{
		while(nb < 1 && nb_exposant <= 110)
		{
			nb *= 10
			nb_exposant++;
		}
	}
	prec = nb_exposant < 106 ? prec : prec++;
	if (ft_strchr(flags, '+') || ft_strchr(flags, ' ') || sign == -1)
		prec++;
	while (*flags)
		ret.size = ret.size < ft_atoi(flags) ? ft_atoi(flags++) : ret.size;
	ret.size = prec < ret.size ? ret.size : prec;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (0);
	return (ret);
}
