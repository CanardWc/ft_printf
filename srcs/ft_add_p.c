/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:21:58 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 20:12:16 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_size_p(t_env *arg, void *pointor)
{
	if (arg->flag[LESS])
	{
		ft_add_to_buff(arg, "0x");
		ft_add_nbr_hexa(arg, (size_t)pointor);
		ft_add_flag_spaces(arg, arg->size, arg->len);
		return (arg->size);
	}
	if (arg->flag[ZERO])
	{
		ft_add_to_buff(arg, "0x");
		if (arg->dot)
			return (2);
		ft_add_flag_zero(arg, arg->size, arg->len);
		ft_add_nbr_hexa(arg, (size_t)pointor);
	}
	else
	{
		ft_add_flag_spaces(arg, arg->size, arg->len);
		ft_add_to_buff(arg, "0x");
		ft_add_nbr_hexa(arg, (size_t)pointor);
	}
	return (arg->size);
}

static int	ft_add_verify_prc_p(t_env *arg, void *pointor)
{
	if (arg->size > arg->precision)
	{
		ft_add_to_buff(arg, "0x");
		ft_add_flag_zero(arg, arg->precision, arg->len - 2);
		ft_add_nbr_hexa(arg, (size_t)pointor);
		ft_add_flag_spaces(arg, arg->size, arg->precision + 2);
		return (arg->size);
	}
	else
	{
		ft_add_to_buff(arg, "0x");
		ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_add_nbr_hexa(arg, (size_t)pointor);
		return (arg->precision);
	}
	return (0);
}

static int	ft_add_prc_p(t_env *arg, void *pointor)
{
	if (arg->size > arg->precision)
	{
		ft_add_flag_spaces(arg, arg->size, arg->precision + 2);
		ft_add_to_buff(arg, "0x");
		ft_add_flag_zero(arg, arg->precision, arg->len - 2);
		ft_add_nbr_hexa(arg, (size_t)pointor);
		return (arg->size);
	}
	else
	{
		ft_add_to_buff(arg, "0x");
		ft_add_flag_zero(arg, arg->precision, arg->len - 2);
		ft_add_nbr_hexa(arg, (size_t)pointor);
		return (arg->precision + 2);
	}
	return (0);
}

static int	ft_add_prc_zero_p(t_env *arg)
{
	if (!arg->size)
	{
		ft_add_to_buff(arg, "0x");
		return (2);
	}
	else
	{
		ft_add_flag_spaces(arg, arg->size, arg->precision + 2);
		ft_add_to_buff(arg, "0x");
		return (arg->size);
	}
	return (0);
}

int			ft_add_p(t_env *arg, va_list ap)
{
	void	*pointor;

	pointor = va_arg(ap, void *);
	arg->len = ft_nbrlen_hexa((unsigned long long)pointor) + 2;
	if (pointor == 0 && arg->dot == 1 && arg->precision == 0)
		return (ft_add_prc_zero_p(arg));
	if (arg->size > arg->len && arg->precision <= arg->len)
		return (ft_add_size_p(arg, pointor));
	if (arg->precision >= arg->len && !arg->flag[LESS])
		return (ft_add_prc_p(arg, pointor));
	if (arg->precision >= arg->len && arg->flag[LESS])
		return (ft_add_verify_prc_p(arg, pointor));
	ft_add_to_buff(arg, "0x");
	ft_add_nbr_hexa(arg, (size_t)pointor);
	return (arg->len);
}
