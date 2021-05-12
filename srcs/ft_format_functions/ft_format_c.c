#include <libftprintf.h>

static void	type_wchar(wchar_t data)
{
	if (data <= 0x7f)
		if (data == 0)
			ft_putchar_fd('~', 1);
	else
		ft_putchar_fd(data, 1);
	else if (data <= 0x7FF)
	{
		ft_putchar_fd((((data & 0x07c0) >> 6) + 0xc0), 1);
		ft_putchar_fd(((data & 0x003F) + 0x80), 1);
	}
	else if (data <= 0xFFFF)
	{
		ft_putchar_fd((((data & 0xF000) >> 12) + 0xE0), 1);
		ft_putchar_fd((((data & 0x0Fc0) >> 6) + 0x80), 1);
		ft_putchar_fd(((data & 0x003F) + 0x80), 1);
	}
	else if (data <= 0x1FFFFF)
	{
		ft_putchar_fd((((data & 0x1c0000) >> 18) + 0xF0), 1);
		ft_putchar_fd((((data & 0x03F000) >> 12) + 0x80), 1);
		ft_putchar_fd((((data & 0x0Fc0) >> 6) + 0x80), 1);
		ft_putchar_fd(((data & 0x003F) + 0x80), 1);
	}
}

int	ft_format_c(t_printf data, t_flags flags, va_list ap)
{
	int		v;
	wint_t	v2;

	v = 0;
	v2 = 0;
	if (flags.nbr > 1)
		data.ret += ft_flag_number(flags, 1);
	if (ft_search(data.s, "l"))
	{
		v2 = va_arg(ap, wint_t);
		type_wchar(v2);
	}
	else
	{
		v = va_arg(ap, int);
		write(1, &v, 1);
	}
	if (flags.min > 1)
		data.ret += ft_flag_min(flags, 1);
	return (data.ret + 1);
}
