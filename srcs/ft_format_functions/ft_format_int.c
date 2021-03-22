#include <libftprintf.h>

static long long int	ft_get_ap_int(va_list ap, const char *s)
{
	if (ft_search(s, "l") && *(ft_search(s, "l") - 1) == 'l')
		return (va_arg(ap, long long int));
	else if (ft_search(s, "l"))
		return ((long long int)va_arg(ap, long int));
	else if (ft_search(s, "h") && *(ft_search(s, "h") - 1) == 'h')
		return ((long long int)va_arg(ap, int));
	else if (ft_search(s, "h"))
		return ((long long int)va_arg(ap, int));
	else
		return ((long long int)va_arg(ap, int));
}

static int		ft_format_int_size(long long int value, t_printf data, t_flags *flags)
{
	int			size;
	unsigned long long int	v;

	size = value == 0 && flags->prec == 0 ? 0 : 1;
	v = value < 0 ? value * -1 : value;
	while ((v /= 10) > 0)
		size++;
	if (flags->prec == 1 && value == 0)
		flags->prec = -1;
	flags->prec -= size;
	flags->zero -= value < 0 || ft_search(data.s, "+") || \
		       ft_search(data.s, " ") ? size + 1 : size;
	if (flags->prec > 0)
		size += flags->prec;
	if (value < 0 || ft_search(data.s, "+") || ft_search(data.s, " "))
		size += 1;
	if (flags->prec < 0 && flags->zero > 0)
		size += flags->zero;
	return (size);
}

static void		ft_putllu_fd(unsigned long long int nbr, int fd)
{
	if (nbr > 9)
		ft_putllu_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + '0', fd);
}

int			ft_format_int(t_printf data, t_flags flags, va_list ap)
{
	long long int	v;
	int		size;

	v = ft_get_ap_int(ap, data.s);
	size = ft_format_int_size(v, data, &flags);
	if (flags.nbr > size)
		data.ret += ft_flag_number(flags, size);
	if (v < 0)
		ft_putchar_fd('-', 1);
	else if (ft_search(data.s, "+"))
		ft_flag_plus();
	else if (ft_search(data.s, " "))
		ft_flag_spc();
	v *= v < 0 ? -1 : 1;
	if (flags.zero > 0 && flags.min == 0 && flags.prec < 0)
		ft_flag_zero(flags);
	if (flags.prec > 0)
		ft_flag_prec(flags);
	if (!(flags.prec == 0 && v == 0))
		ft_putllu_fd(v, 1);
	if (flags.min > size)
		data.ret += ft_flag_min(flags, size);
	return (data.ret + size);
}