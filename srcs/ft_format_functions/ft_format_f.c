/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:30:13 by edassess          #+#    #+#             */
/*   Updated: 2021/02/02 13:30:49 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>

double		ft_get_ap_f(va_list ap, const char *s)
{
	if (ft_search(s, "l"))
		return ((double)va_arg(ap, double));
	else
		return ((double)va_arg(ap, double));
}

int		ft_format_f(t_printf data, t_flags flag, va_list ap)
{
	t_dbl	v;
	int	size;

	//	get size
	v = ft_getdbl(ft_get_ap_f(ap, data.s));
	if (v.pow >= 0)
	{
		size = 2;
		if (flag.prec == 0)
		{
			if (ft_search(data.s, "#"))
				size = 2;
			else
				size = 1;
		}
		flag.min = 0;
		size += v.pow;
		if (flag.prec > -1)
			size += flag.prec;
		else
		{
			size += 6;
			flag.prec = 6;
		}
		if (ft_search(data.s, " ") || ft_search(data.s, "+") || v.sign < 0)
			size++;
		flag.zero -= size;

		//	flag nbr
		if (flag.nbr > size)
			data.ret += ft_flag_number(flag, size);

		//	space < plus flag
		if (v.sign < 0)
			ft_putchar_fd('-', 1);
		else if (ft_search(data.s, "+"))
			ft_flag_plus();
		else if (ft_search(data.s, " "))
			ft_flag_spc();

		//	zero flag
		if (flag.zero > 0)
			ft_flag_zero(flag);
		v.pow++;
		while (v.pow--)
		{
			ft_putchar_fd(*v.decimal++, 1);
			printf("1");
		}
		if (ft_search(data.s, "#") || flag.prec > 0)
			ft_putchar_fd('.', 1);
		while (flag.prec--)
		{
			if (*v.decimal)
				ft_putchar_fd(*v.decimal++, 1);
			else
				ft_putchar_fd('0', 1);
		}
	}
	else
	{
	size = 0;
	}
	//	ft_putstr_fd(v.decimal, 1);
	return (data.ret + size);
}
