#include <libftprintf.h>

int	ft_format_f(t_printf data, t_flags flags, va_list ap)
{
	static char	*limits[] = {"nan", "inf", "-inf"};
	t_dbl		v;
	int			size;

	size = 0;
	v = ft_getdbl((double)va_arg(ap, double));
	if (v.pow >= 400)
	{
		size = ft_strlen(limits[v.pow - 400]);
		if (flags.nbr > size)
			data.ret += ft_flag_number(flags, size);
		if (flags.zero > size)
		{
			data.ret += flags.zero - size;
			while (flags.zero-- > size)
				ft_putchar_fd(' ', 1);
		}
		ft_putstr_fd(limits[v.pow - 400], 1);
		if (flags.min > size)
			data.ret += ft_flag_min(flags, size);
		return (data.ret + size);
	}
	return (ft_dbl_case_f(data, flags, v));
}
