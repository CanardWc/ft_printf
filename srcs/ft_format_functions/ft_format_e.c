/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:24:58 by edassess          #+#    #+#             */
/*   Updated: 2021/04/26 16:29:39 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

double		ft_get_ap_e(va_list ap, const char *s)
{
	if (ft_search(s, "l"))
		return ((double)va_arg(ap, double));
	else
		return ((double)va_arg(ap, double));
}

#include <stdio.h>

int		ft_format_e(t_printf data, t_flags flags, va_list ap)
{
	t_dbl	v;
	char	*to_free;
	int	size;
	int	div;

	v = ft_getdbl(ft_get_ap_e(ap, data.s));
	//	printf("v.sign = %d\n", v.sign);
	//	printf("v.decimal = %s\n", v.decimal);
	//	printf("v.pow = %d\n", v.pow);
	// getting size
	if (v.pow >= 400)
	{
		if (v.pow == 400)
		{
			if (flags.nbr > 3)
				data.ret += ft_flag_number(flags, 3);
			if (flags.zero > 3)
			{
				data.ret += flags.zero - 3;
				while (flags.zero-- > 3)
					ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd("nan", 1);
			if (flags.min > 3)
				data.ret += ft_flag_min(flags, 3);
			return (data.ret + 3);
		}
		if (v.pow == 401)
		{
			if (flags.nbr > 3)
				data.ret += ft_flag_number(flags, 3);
			if (flags.zero > 3)
			{
				data.ret += flags.zero - 3;
				while (flags.zero-- > 3)
					ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd("inf", 1);
			if (flags.min > 3)
				data.ret += ft_flag_min(flags, 3);
			return (data.ret + 3);
		}
		if (v.pow == 402)
		{
			size = 4;
			if (flags.nbr > 4)
				data.ret += ft_flag_number(flags, 4);
			if (flags.zero > 4)
			{
				data.ret += flags.zero - 4;
				while (flags.zero-- > 4)
					ft_putchar_fd(' ', 1);
			}
			ft_putstr_fd("-inf", 1);
			if (flags.min > 4)
				data.ret += ft_flag_min(flags, 4);
			return (data.ret + 4);
		}
	}

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
