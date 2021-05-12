<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_g.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:13:33 by edassess          #+#    #+#             */
/*   Updated: 2021/05/07 11:31:34 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	ft_limits_g(t_printf data, t_flags f, t_dbl v)
{
	static char	*limits[] = {"nan", "inf", "-inf"};
	int			size;

	size = ft_strlen(limits[v.pow - 400]);
	if (f.nbr > size)
		data.ret += ft_flag_number(f, size);
	if (f.zero > size)
	{
		data.ret += f.zero - size;
		while (f.zero-- > size)
			ft_putchar_fd(' ', 1);
	}
	ft_putstr_fd(limits[v.pow - 400], 1);
	if (f.min > size)
		data.ret += ft_flag_min(f, size);
	return (data.ret + size);
}

int	ft_g_format_e(t_printf data, t_flags f, t_dbl v, int i)
{
	int	size;

=======
#include <libftprintf.h>

static int	ft_inf_case(t_printf data, t_flags flags, t_dbl v)
{
	static char	*limits[] = {"nan", "inf", "-inf"};
	int			size;

	size = 0;
	size = ft_strlen(limits[v.pow - 400]);
	if (v.pow - 400 == 1 && (ft_search(data.s, "+") || ft_search(data.s, " ")))
		size++;
	if (flags.nbr > size)
		data.ret += ft_flag_number(flags, size);
	if (flags.zero > size)
	{
		data.ret += flags.zero - size;
		while (flags.zero-- > size)
			ft_putchar_fd(' ', 1);
	}
	if (v.pow - 400 == 1 && ft_search(data.s, "+"))
		ft_putchar_fd('+', 1);
	else if (v.pow - 400 == 1 && ft_search(data.s, " "))
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(limits[v.pow - 400], 1);
	if (flags.min > size)
		data.ret += ft_flag_min(flags, size);
	return (data.ret + size);
}

int	ft_format_g(t_printf data, t_flags flags, va_list ap)
{
	t_dbl		v;
	int			size;
	int			i;

	if (flags.prec == -1)
		flags.prec = 6;
	v = ft_getdbl(va_arg(ap, double));
	if (v.pow >= 400)
		return (ft_inf_case(data, flags, v));
	if (flags.prec == 0 && v.pow >= 0)
		size = 1;
	else if (v.pow < 0 && flags.prec == 0)
		size = 1;
	else
		size = flags.prec;
	v = ft_round_dbl(v, size);
>>>>>>> a6a17a6ab8d5e25edf8efe101414f3888a63b040
	size = 0;
	if (v.pow < -4)
	{
		if (!ft_search(data.s, "#"))
			f.prec = (f.prec >= 0) * i;
		else
			f.prec -= v.pow + 1;
		return (ft_dbl_case_e(data, f, v));
	}
	else
	{
		if (!ft_search(data.s, "#"))
		{
			f.prec = i - v.pow;
			while (v.decimal[v.pow + size] && v.decimal[v.pow + size] == '0')
				size++;
			if (f.prec < 0 || !v.decimal[v.pow + size])
				f.prec = 0;
		}
		else if (f.prec != 0)
			f.prec -= v.pow + 1;
		return (ft_dbl_case_e(data, f, v));
	}
}

int	ft_g_format_f(t_printf data, t_flags f, t_dbl v, int i)
{
	int	size;

	size = 0;
	if (!ft_search(data.s, "#"))
	{
		while (v.decimal[size] && v.decimal[size] != '0' && size < f.prec)
			size++;
		f.prec = i - (v.pow);
		if (f.prec < 0 || size == 0)
			f.prec = 0;
		if (f.prec == 0 && v.pow < 0)
			f.prec = -v.pow;
	}
	else if (f.prec != 0)
	{
		f.prec -= v.pow + 1;
	}
	return (ft_dbl_case_f(data, f, v));
}

int	ft_format_g(t_printf data, t_flags f, va_list ap)
{
	t_dbl		v;
	int			size;
	int			i;

	if (f.prec == -1)
		f.prec = 6;
	v = ft_getdbl(va_arg(ap, double));
	if (v.pow >= 400)
		return (ft_limits_g(data, f, v));
	size = (f.prec == 0) + ((f.prec != 0) * f.prec);
	v = ft_round_dbl(v, size);
	size = 0;
	i = ft_strlen(v.decimal) - 1;
	while (i >= 0 && v.decimal[i] == '0')
		i--;
	while (v.decimal[v.pow + size] && v.decimal[v.pow + size] == '0')
		size++;
	if (v.pow < -4 || (f.prec == 0 && f.prec < v.pow) \
			|| (f.prec != 0 && f.prec <= v.pow))
		return (ft_g_format_e(data, f, v, i));
	return (ft_g_format_f(data, f, v, i));
}
