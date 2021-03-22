/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:21:15 by edassess          #+#    #+#             */
/*   Updated: 2021/02/02 13:21:17 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_format_c(t_printf data, t_flags flags, va_list ap)
{
	data.s = (void *)data.s;
	if (flags.nbr > 1)
		data.ret += ft_flag_number(flags, 1);
	ft_putchar_fd(va_arg(ap, int), 1);
	if (flags.min > 1)
		data.ret += ft_flag_min(flags, 1);
	return (data.ret + 1);
}
