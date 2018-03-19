/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:22:22 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:22:28 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_size_s(t_env *arg, char *str)
{
	if (arg->flag[LESS])
	{
		ft_printf_putstr(arg, str);
		ft_add_flag_spaces(arg, arg->size, arg->len);
		return (arg->size);
	}
	if (arg->flag[ZERO])
		ft_add_flag_zero(arg, arg->size, arg->len);
	else
		ft_add_flag_spaces(arg, arg->size, arg->len);
	ft_printf_putstr(arg, str);
	return (arg->size);
}

static int	ft_add_verify_prc_s(t_env *arg, char *str)
{
	if (arg->size > arg->precision && arg->precision < arg->len)
	{
		ft_add_str_n(arg, str, arg->precision);
		ft_add_flag_spaces(arg, arg->size, arg->precision);
		return (arg->size);
	}
	else
	{
		ft_add_str_n(arg, str, arg->precision);
		return (ft_nbcmp_min(arg->precision, arg->len));
	}
	return (0);
}

static int	ft_add_prc_s(t_env *arg, char *str)
{
	if (arg->size > arg->precision && arg->precision)
	{
		if (arg->flag[ZERO])
			ft_add_flag_zero(arg, arg->size, arg->precision);
		else
			ft_add_flag_spaces(arg, arg->size, arg->precision);
		ft_add_str_n(arg, str, arg->precision);
		return (arg->size);
	}
	else if (arg->precision < arg->len)
		ft_add_str_n(arg, str, arg->precision);
	return (ft_nbcmp_min(arg->precision, arg->len));
}

static int	ft_add_prc_zero_s(t_env *arg)
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

int			ft_add_s(t_env *arg, va_list ap)
{
	char	*str;

	if (arg->modif[L] == 1)
		return (ft_add_ws(arg, ap));
	else
		str = va_arg(ap, char *);
	arg->len = ft_printf_strlen(str);
	if (arg->dot == 1 && arg->precision == 0)
		return (ft_add_prc_zero_s(arg));
	if (arg->size > arg->len &&
			(arg->precision >= arg->len || !arg->dot))
		return (ft_add_size_s(arg, str));
	if (arg->dot && (arg->size > arg->len
				|| arg->precision < arg->len) && !arg->flag[LESS])
		return (ft_add_prc_s(arg, str));
	if (arg->dot && (arg->size > arg->len
				|| arg->precision < arg->len) && arg->flag[LESS])
		return (ft_add_verify_prc_s(arg, str));
	ft_printf_putstr(arg, str);
	return (arg->len);
}
