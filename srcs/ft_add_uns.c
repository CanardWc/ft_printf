/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_uns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:24:44 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:25:04 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_size_uns(t_env *arg, size_t nbr)
{
	if (arg->flag[LESS])
	{
		ft_printf_putnbr_uns(arg, nbr);
		ft_add_flag_spaces(arg, arg->size, arg->len);
		return (arg->size);
	}
	if (arg->flag[ZERO] && !arg->dot)
		ft_add_flag_zero(arg, arg->size, arg->len);
	else
		ft_add_flag_spaces(arg, arg->size, arg->len);
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->size);
}

static int	ft_add_verify_prc_uns(t_env *arg, size_t nbr)
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

static int	ft_add_prc_uns(t_env *arg, size_t nbr)
{
	if (arg->size > arg->precision)
	{
		ft_add_flag_spaces(arg, arg->size, arg->precision);
		ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_add_nbr_uns(arg, nbr);
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

static int	ft_add_precision_zero_uns(t_env *arg)
{
	if (!arg->size)
		return (0);
	else
	{
		ft_add_flag_spaces(arg, arg->size, arg->precision);
		return (arg->size);
	}
}

int			ft_add_uns(t_env *arg, size_t nbr)
{
	arg->len = ft_printf_nbrlen_uns(arg, nbr);
	if (nbr == 0 && arg->dot == 1)
		return (ft_add_precision_zero_uns(arg));
	if (arg->size > arg->len && arg->precision <= arg->len)
		return (ft_add_size_uns(arg, nbr));
	if (arg->precision >= arg->len && !arg->flag[LESS])
		return (ft_add_prc_uns(arg, nbr));
	if (arg->precision >= arg->len && arg->flag[LESS])
		return (ft_add_verify_prc_uns(arg, nbr));
	ft_printf_putnbr_uns(arg, nbr);
	return (arg->len);
}
