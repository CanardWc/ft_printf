/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:21:28 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:21:15 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_size_octal(t_env *arg, size_t nbr)
{
	if (arg->flag[LESS])
	{
		arg->len += ft_add_flag_diese(arg);
		ft_printf_putnbr_uns(arg, nbr);
		ft_add_flag_spaces(arg, arg->size, arg->len);
		return (arg->size);
	}
	if (arg->flag[DIESE])
		arg->len++;
	if (arg->flag[ZERO] && !arg->dot)
		ft_add_flag_zero(arg, arg->size, arg->len);
	else
		ft_add_flag_spaces(arg, arg->size, arg->len);
	ft_add_flag_diese(arg);
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->size);
}

static int	ft_add_verify_prc_octal(t_env *arg, size_t nbr)
{
	if (arg->size > arg->precision)
	{
		ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		ft_add_flag_spaces(arg, arg->size, arg->precision);
		return (arg->size);
	}
	else
	{
		ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		return (arg->precision);
	}
	return (0);
}

static int	ft_add_prc_octal(t_env *arg, size_t nbr)
{
	if (arg->size > arg->precision)
	{
		ft_add_flag_spaces(arg, arg->size, arg->precision);
		ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		return (arg->size);
	}
	else
	{
		ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_printf_putnbr_uns(arg, nbr);
		return (arg->precision);
	}
	return (0);
}

static int	ft_add_prc_zero_octal(t_env *arg)
{
	if (!arg->flag[DIESE])
	{
		if (!arg->size)
			return (0);
		ft_add_flag_spaces(arg, arg->size, arg->precision);
		return (arg->size);
	}
	else if (arg->flag[DIESE])
	{
		if (!arg->size)
			return (ft_add_flag_diese(arg));
		if (arg->flag[LESS])
		{
			ft_add_c_to_buff(arg, '0');
			ft_add_flag_spaces(arg, arg->size, arg->precision + 1);
		}
		else
		{
			ft_add_flag_spaces(arg, arg->size, arg->precision + 1);
			ft_add_c_to_buff(arg, '0');
		}
		return (arg->size);
	}
	return (0);
}

int			ft_add_octal(t_env *arg, size_t nbr)
{
	arg->len = ft_printf_nbrlen_uns(arg, nbr);
	if (nbr == 0 && arg->dot && arg->precision == 0)
		return (ft_add_prc_zero_octal(arg));
	if (nbr > 0 && arg->flag[DIESE] && !arg->flag[LESS] &&
			arg->size < arg->len && arg->precision == 0)
	{
		arg->len += ft_add_flag_diese(arg);
		ft_printf_putnbr_uns(arg, nbr);
		return (arg->len);
	}
	if (arg->size > arg->len && arg->precision <= arg->len)
		return (ft_add_size_octal(arg, nbr));
	if (arg->precision >= arg->len && !arg->flag[LESS])
		return (ft_add_prc_octal(arg, nbr));
	if (arg->precision >= arg->len && arg->flag[LESS])
		return (ft_add_verify_prc_octal(arg, nbr));
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->len);
}
