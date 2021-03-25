#include <libftprintf.h>

double		ft_get_ap_g(va_list ap, const char *s)
{
	if (ft_search(s, "l"))
		return ((double)va_arg(ap, double));
	else
		return ((double)va_arg(ap, double));
}

int	ft_format_g(t_printf data, t_flags flags, va_list ap)
{
	t_dbl	v;
	int	size;

	size = 1;
	flags.min = 0;
	v = ft_getdbl(ft_get_ap_g(ap, data.s));
	ft_putstr_fd(v.decimal, 1);
	return (data.ret + size);
}
