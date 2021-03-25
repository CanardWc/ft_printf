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
	int	size;

	size = 1;
	flags.min = 0;
	v = ft_getdbl(ft_get_ap_e(ap, data.s));
	ft_putstr_fd(v.decimal, 1);
	return (data.ret + size);
}
