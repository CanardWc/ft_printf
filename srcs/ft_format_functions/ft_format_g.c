/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_g.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:49:23 by edassess          #+#    #+#             */
/*   Updated: 2021/05/06 17:23:05 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	ft_format_g(t_printf data, t_flags flags, va_list ap)
{
	t_dbl		v;
	int			size;
	int			i;
	static char	*limits[] = {"nan", "inf", "-inf"};

	if (flags.prec == -1)
		flags.prec = 6;
	v = ft_getdbl(va_arg(ap, double));
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
	if (flags.prec == 0 && v.pow >= 0)
		size = 1;
	else if (v.pow < 0 && flags.prec == 0)
		size = 1;
	else
		size = flags.prec;
	v = ft_round_dbl(v, size);
	size = 0;
	if (v.pow < -4)
	{
		if (!ft_search(data.s, "#"))
		{
			i = ft_strlen(v.decimal) - 1;
			while (i >= 0 && v.decimal[i] == '0')
				i--;
			flags.prec = i;
			while (v.decimal[v.pow + size] && v.decimal[v.pow + size] == '0')
				size++;
			if (flags.prec < 0)
				flags.prec = 0;
		}
		else
			flags.prec -= v.pow + 1;
		return (ft_dbl_case_e(data, flags, v));
	}
	if ((flags.prec == 0 && flags.prec < v.pow) \
			|| (flags.prec != 0 && flags.prec <= v.pow))
	{
		i = ft_strlen(v.decimal) - 1;
		while (i >= 0 && v.decimal[i] == '0')
			i--;
		if (!ft_search(data.s, "#"))
		{
			flags.prec = i - v.pow;
			if (flags.prec < 0)
				flags.prec = 0;
			while (v.decimal[v.pow + size] && v.decimal[v.pow + size] == '0')
				size++;
			if (!v.decimal[v.pow + size])
				flags.prec = 0;
		}
		else if (flags.prec != 0)
			flags.prec -= v.pow + 1;
		return (ft_dbl_case_e(data, flags, v));
	}
	if (!ft_search(data.s, "#"))
	{
		while (v.decimal[size] && v.decimal[size] != '0' && size < flags.prec)
			size++;
		i = ft_strlen(v.decimal) - 1;
		while (i >= 0 && v.decimal[i] == '0')
			i--;
		flags.prec = i - (v.pow);
		if (flags.prec < 0)
			flags.prec = 0;
		if (size == 0)
			flags.prec = 0;
		if (flags.prec == 0 && v.pow < 0)
			flags.prec = -v.pow;
	}
	else if (flags.prec != 0)
		flags.prec -= v.pow + 1;
	return (ft_dbl_case_f(data, flags, v));
}
