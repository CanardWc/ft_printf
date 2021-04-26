/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:30:13 by edassess          #+#    #+#             */
/*   Updated: 2021/03/30 15:54:40 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>

double	ft_get_ap_f(va_list ap, const char *s)
{
	if (ft_search(s, "l"))
		return ((double)va_arg(ap, double));
	else
		return ((double)va_arg(ap, double));
}

void	ft_putflags(t_printf data, t_flags flag, t_dbl v, int size)
{
	flag.zero -= size;
	if (flag.nbr > size)
		data.ret += ft_flag_number(flag, size);
	if (v.sign < 0)
		ft_putchar_fd('-', 1);
	else if (ft_search(data.s, "+"))
		ft_flag_plus();
	else if (ft_search(data.s, " "))
		ft_flag_spc();
	if (flag.zero > 0)
		ft_flag_zero(flag);
}

int	ft_posexp_f(t_printf data, t_flags flag, t_dbl v, int size)
{
	char	*freed;

	size += flag.prec;
	v = ft_round_dbl(v, size);
	freed = v.decimal;
	size += v.sign < 0 || ft_search(data.s, "+") || ft_search(data.s, " ");
	size += flag.prec != 0 || ft_search(data.s, "#");
	ft_putflags(data, flag, v, size);
	while (v.pow-- > -1)
		if (*v.decimal)
			ft_putchar_fd(*v.decimal++, 1);
		else
			ft_putchar_fd('0', 1);
	if (ft_search(data.s, "#") || flag.prec > 0)
		ft_putchar_fd('.', 1);
	while (flag.prec--)
		if (*v.decimal)
			ft_putchar_fd(*v.decimal++, 1);
		else
			ft_putchar_fd('0', 1);
	while (size++ < flag.min)
		ft_putchar_fd(' ', 1);
	free(freed);
	return (data.ret + size);
}

int	ft_negexp_f(t_printf data, t_flags flag, t_dbl v, int size)
{
	char	*freed;

	flag.min += v.pow;
	flag.min -= v.sign < 0 || ft_search(data.s, "+") || ft_search(data.s, " ");
	v = ft_round_dbl(v, flag.prec + (v.pow + 1));
	freed = v.decimal;
	size = (flag.prec == 0 && !ft_search(data.s, "#")) + flag.prec;
	if (v.pow == 0)
		return (ft_posexp_f(data, flag, v, v.pow + 1));
	ft_putflags(data, flag, v, size + (v.sign < 0 || ft_search(data.s, "+") || \
				ft_search(data.s, " ")) + (-v.pow));
	ft_putchar_fd('0', 1);
	if ((flag.prec == 0 && ft_search(data.s, "#")) || flag.prec != 0)
		ft_putchar_fd('.', 1);
	while (++v.pow < 0 && --size)
		ft_putchar_fd('0', 1);
	while (--size >= 0)
		if (*v.decimal && flag.min--)
			ft_putchar_fd(*v.decimal++, 1);
		else if (flag.min--)
			ft_putchar_fd('0', 1);
	while (--flag.min > 0)
		ft_putchar_fd(' ', 1);
	free(freed);
	return (data.ret + size);
}

int	ft_format_f(t_printf data, t_flags flag, va_list ap)
{
	t_dbl	v;
	int		size;

	v = ft_getdbl(ft_get_ap_f(ap, data.s));
	size = v.pow + 1;
	if (flag.prec == -1)
		flag.prec = 6;
	if (v.pow >= 0)
		return (ft_posexp_f(data, flag, v, size));
	else
		return (ft_negexp_f(data, flag, v, size));
}
