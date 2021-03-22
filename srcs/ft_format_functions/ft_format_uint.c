#include <libftprintf.h>

const char	*bases[] =  { 
	"0123456789", 
	"01234567", 
	"0123456789abcdef", 
	"0123456789ABCDEF",
	"0123456789abcdef" }; 

static unsigned long long int	ft_get_ap_uint(va_list ap, const char *s)
{
	if (ft_search(s, "l") && *(ft_search(s, "l") - 1) == 'l')
		return (va_arg(ap, unsigned long long int));
	else if (ft_search(s, "l"))
		return ((unsigned long long int)va_arg(ap, unsigned long int));
	else if (ft_search(s, "h") && *(ft_search(s, "h") - 1) == 'h')
		return ((unsigned long long int)va_arg(ap, unsigned int));
	else if (ft_search(s, "h"))
		return ((unsigned long long int)va_arg(ap, unsigned int));
	else
		return ((unsigned long long int)va_arg(ap, unsigned int));
}

static int		ft_uint_size(unsigned long long int value, \
		const char *base, t_printf data, t_flags *flags)
{
	int	size;

	size = flags->prec == 0 && value == 0 ? 0 : 1;
	if (*(data.s) != 'p' && ft_search(data.s, "#") && value != 0)
	{
		size += 2;
		flags->prec += 2;
	}
	if (flags->prec == 1 && value == 0)
		flags->prec = -1;
	while ((value /= ft_strlen(base)) > 0)
		size++;
	flags->prec -= size;
	flags->zero -= size;
	if (flags->prec > 0)
		size += flags->prec;
	else if (flags->prec < 0 && flags->zero > 0)
		size += flags->zero;
	return (*(data.s) == 'p' ? size + 2 : size);
}

static void		ft_putllu_fd(unsigned long long int nbr, const char *base, int fd)
{
	if (nbr > (ft_strlen(base) - 1))
		ft_putllu_fd(nbr / ft_strlen(base), base, fd);
	ft_putchar_fd(base[nbr % ft_strlen(base)], fd);
}

int			ft_format_uint(t_printf data, t_flags flags, va_list ap)
{
	char			*form = "uoxXp";
	const char		*base;
	int			size;
	unsigned long long int	v;

	base = bases[ft_strchr(form, *(data.s)) - form];
	if (*(data.s) == 'p')
		v = va_arg(ap, unsigned long long int);
	else
		v = ft_get_ap_uint(ap, data.s);
	size = ft_uint_size(v, base, data, &flags);
	if (flags.nbr > size)
		data.ret += ft_flag_number(flags, size);
	if (((ft_search(data.s, "#") && v != 0) || *(data.s) == 'p') && \
			*(data.s) != 'u')
		ft_flag_hash(*(ft_strchr(form, *(data.s))));
	if (flags.zero > 0 && flags.min <= 0)
		ft_flag_zero(flags);
	if (flags.prec > 0)
		ft_flag_prec(flags);
	if (!(flags.prec == 0 && v == 0))
		ft_putllu_fd(v, base, 1);
	if (flags.min > size)
		data.ret += ft_flag_min(flags, size);
	return (data.ret + size);
}