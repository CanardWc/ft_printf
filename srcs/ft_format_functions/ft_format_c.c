/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:21:15 by edassess          #+#    #+#             */
/*   Updated: 2021/04/26 15:31:15 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static int	ft_get_ap_c(va_list ap, const char *s)
{
	if (ft_search(s, "l"))
		return ((int)va_arg(ap, wint_t));
	else
		return (va_arg(ap, int));
}

int		ft_format_c(t_printf data, t_flags flags, va_list ap)
{
	int	v;

	v = ft_get_ap_c(ap, data.s);
	if (flags.nbr > 1)
		data.ret += ft_flag_number(flags, 1);
	ft_putchar_fd(v, 1);
	if (flags.min > 1)
		data.ret += ft_flag_min(flags, 1);
	return (data.ret + 1);
}
