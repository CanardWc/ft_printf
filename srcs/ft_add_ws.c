/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_ws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:26:02 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 23:32:49 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_size_ws(t_env *arg, wchar_t *str)
{
	if (arg->flag[LESS])
	{
		ft_printf_putwstr(arg, str);
		ft_add_flag_spaces(arg, arg->size, arg->len);
		return (arg->size);
	}
	if (arg->flag[ZERO])
		ft_add_flag_zero(arg, arg->size, arg->len);
	else
		ft_add_flag_spaces(arg, arg->size, arg->len);
	ft_printf_putwstr(arg, str);
	return (arg->size);
}

static int	ft_add_verify_prc_ws(t_env *arg, wchar_t *str)
{
	if (arg->size > arg->precision && arg->precision < arg->len)
	{
		ft_add_wstr_n(arg, str, arg->precision);
		ft_add_flag_spaces(arg, arg->size, arg->precision);
		return (arg->size);
	}
	else
	{
		ft_add_wstr_n(arg, str, arg->precision);
		return (ft_nbcmp_min(arg->precision, arg->len));
	}
	return (0);
}

static int	ft_add_prc_ws(t_env *arg, wchar_t *str)
{
	if (arg->size > arg->precision && arg->precision < arg->len)
	{
		if (arg->flag[ZERO])
			ft_add_flag_zero(arg, arg->size, ft_strwlen_n(str, arg->precision));
		else
			ft_add_flag_spaces(arg, arg->size, ft_strwlen_n(str, \
						arg->precision));
		ft_add_wstr_n(arg, str, arg->precision);
		return (arg->size);
	}
	else if (arg->precision < arg->len)
		ft_add_wstr_n(arg, str, arg->precision);
	return (ft_nbcmp_min(arg->precision, ft_strwlen_n(str, arg->precision)));
}

static int	ft_add_prc_zero_ws(t_env *arg)
{
	if (!arg->size)
		return (0);
	else
	{
		if (arg->flag[ZERO])
			ft_add_flag_zero(arg, arg->size, 0);
		else
			ft_add_flag_spaces(arg, arg->size, 0);
		return (arg->size);
	}
}

int			ft_add_ws(t_env *arg, va_list ap)
{
	wchar_t	*str;

	str = va_arg(ap, wint_t *);
	arg->len = ft_printf_strwlen(str);
	if (arg->dot && arg->precision == 0)
		return (ft_add_prc_zero_ws(arg));
	if (arg->size > arg->len &&
			(arg->precision >= arg->len || !arg->dot))
		return (ft_add_size_ws(arg, str));
	if (arg->dot && (arg->size > arg->len ||
				arg->precision < arg->len) && !arg->flag[LESS])
		return (ft_add_prc_ws(arg, str));
	if (arg->dot && (arg->size > arg->len ||
				arg->precision < arg->len) && arg->flag[LESS])
		return (ft_add_verify_prc_ws(arg, str));
	ft_printf_putwstr(arg, str);
	return (arg->len);
}
