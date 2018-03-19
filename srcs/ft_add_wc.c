/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_wc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:25:36 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:25:24 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_verify_size_wc(t_env *arg, wchar_t c)
{
	int	i;

	i = 0;
	ft_add_wchar(arg, c);
	i += ft_add_flag_spaces(arg, arg->size, 1);
	return (arg->size);
}

static int	ft_add_size_wc(t_env *arg, wchar_t c)
{
	int	i;

	i = 0;
	if (arg->flag[LESS])
		return (ft_add_verify_size_wc(arg, c));
	else
	{
		if (arg->flag[ZERO])
			arg->len += ft_add_flag_zero(arg, arg->size, arg->len);
		else
			i += ft_add_flag_spaces(arg, arg->size, 1);
		ft_add_wchar(arg, c);
	}
	return (arg->size);
}

int			ft_add_wc(t_env *arg, va_list ap)
{
	wchar_t	c;

	c = va_arg(ap, wint_t);
	arg->len = ft_wcharlen(c);
	if (arg->size > arg->len && (!arg->dot || arg->dot))
		return (ft_add_size_wc(arg, c));
	ft_add_wchar(arg, c);
	return (arg->len);
}
