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

long double	ft_get_ap_f(va_list ap, const char *s)
{
	if (ft_strchr(s, "l"))
		return ((long double)va_arg(ap, long double));
	else
		return ((long double)va_arg(ap, double));
}

int		ft_format_f(va_list ap, const char *s, int i)
{
	long double	prec;
	long double	v;

	v = ft_get_ap_f(ap, flags);
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) : 6;
	if (prec > 0)
		ret.str[(int)(size-- - prec)] = '.';
	while (prec > 0)
		ft_putnbr_fd(ft_dmod((v * (10 * prec--)), 10) + '0', 1);
	while (i > 10)
	{
		ret.str[(int)--size] = ft_dmod(v, 10) + '0';
		v /= 10;
	}
	ret.str[(int)--size] = ft_dmod(v, 10) + '0';
	return (ret.str);
}
