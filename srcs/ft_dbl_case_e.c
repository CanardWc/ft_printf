#include <libftprintf.h>

int		ft_dbl_case_e(t_printf data, t_flags flags, t_dbl v)
{
	char	*to_free;
	int	size;
	int	div;

	// getting size

	div = 1;
	size = 1;
	if (flags.prec >= 0)
		size += flags.prec;
	else
		size += 6;
	v = ft_round_dbl(v, size);

	to_free = v.decimal;	
	size += 4;
	if (v.pow > 99 || v.pow < -99)
		size++;
	if (flags.prec != 0 || ft_search(data.s, "#"))
		size++;
	if (v.sign < 0 || ft_search(data.s, "+") || ft_search(data.s, " "))
		size++;
	flags.zero -= size;

	// number flag

	if (flags.nbr > size)
		data.ret += ft_flag_number(flags, size);

	// space < plus flag

	if (v.sign < 0)
		ft_putchar_fd('-', 1);
	else if (ft_search(data.s, "+"))
		ft_flag_plus();
	else if (ft_search(data.s, " "))
		ft_flag_spc();

	// zero flag

	if (flags.zero > 0)
		ft_flag_zero(flags);
	if (flags.zero > 0)
		data.ret += flags.zero;
	ft_putchar_fd(*v.decimal++, 1);

	// hash flag / precision flag

	if (flags.prec > 0 || ft_search(data.s, "#") || flags.prec < 0)
	{
		ft_putchar_fd('.', 1);
		if (flags.prec < 0)
			flags.prec = 6;
		while (*v.decimal && flags.prec-- > 0)
			ft_putchar_fd(*v.decimal++, 1);
		while (flags.prec-- > 0)
			ft_putchar_fd('0', 1);
	}

	ft_putchar_fd('e', 1);
	if (v.pow < 0)
	{
		v.pow *= -1;
		ft_putchar_fd('-', 1);
	}
	else
		ft_putchar_fd('+', 1);
	if (v.pow < 10)
		ft_putchar_fd('0', 1);
	ft_putnbr_fd(v.pow, 1);

	// min flag

	if (flags.min > size)
		data.ret += ft_flag_min(flags, size);
	free(to_free);
	to_free = NULL;
	v.decimal = NULL;
	return  (data.ret + size);
}
