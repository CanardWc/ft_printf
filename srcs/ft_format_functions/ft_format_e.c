/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:24:58 by edassess          #+#    #+#             */
/*   Updated: 2021/02/02 13:28:16 by edassess         ###   ########lyon.fr   */
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

int		ft_format_e(t_printf data, t_flags flags, va_list ap)
{
	t_dbl	v;
	char	*to_free;
	int	size;
	int	div;

	v = ft_getdbl(ft_get_ap_e(ap, data.s));
	to_free = v.decimal;	
	// getting size

	div = 1;
	size = 4;
	if (v.pow > 99 || v.pow < -99)
		size++;
	else if (flags.prec == 0 && !ft_search(data.s, "#"))
		size++;
	else
		size += 2;
	if (flags.prec >= 0)
		size += flags.prec;
	else
		size += 6;
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
	return  (data.ret + size);
}
