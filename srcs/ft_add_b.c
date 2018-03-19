/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:19:20 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:12:52 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_size_b(t_env *arg, size_t nbr)
{
	if (arg->flag[LESS])
	{
		arg->len += ft_add_flag_diese(arg);
		ft_add_nbr_base(arg, nbr, BINARY);
		ft_add_flag_spaces(arg, arg->size, arg->len);
		return (arg->size);
	}
	if (arg->flag[DIESE])
		arg->len += 2;
	if (arg->flag[ZERO] && !arg->dot)
	{
		ft_add_flag_diese(arg);
		ft_add_flag_zero(arg, arg->size, arg->len);
		ft_add_nbr_base(arg, nbr, BINARY);
	}
	else
	{
		ft_add_flag_spaces(arg, arg->size, arg->len);
		ft_add_flag_diese(arg);
		ft_add_nbr_base(arg, nbr, BINARY);
	}
	return (ft_nbcmp_max(arg->len, arg->size));
}

static int	ft_add_verify_prc_b(t_env *arg, size_t nbr)
{
	int		lenfin;

	lenfin = 0;
	if (arg->size > arg->precision)
	{
		lenfin += ft_add_flag_diese(arg);
		ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_add_nbr_base(arg, nbr, BINARY);
		ft_add_flag_spaces(arg, arg->size, arg->precision + lenfin);
		return (arg->size);
	}
	else
	{
		lenfin += ft_add_flag_diese(arg);
		lenfin += ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_add_nbr_base(arg, nbr, BINARY);
		arg->len += lenfin;
		return (ft_nbcmp_max(arg->len, arg->precision));
	}
	return (0);
}

static int	ft_add_prc_b(t_env *arg, size_t nbr)
{
	int		lenfin;

	lenfin = 0;
	if (arg->size > arg->precision)
	{
		if (arg->flag[DIESE])
			lenfin = 2;
		ft_add_flag_spaces(arg, arg->size, arg->precision + lenfin);
		ft_add_flag_diese(arg);
		ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_add_nbr_base(arg, nbr, BINARY);
		return (arg->size);
	}
	else
	{
		lenfin += ft_add_flag_diese(arg);
		lenfin += ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_add_nbr_base(arg, nbr, BINARY);
		arg->len += lenfin;
		return (ft_nbcmp_max(arg->len, arg->precision));
	}
	return (0);
}

static int	ft_add_prc_zero_b(t_env *arg, size_t nbr)
{
	if (nbr == 0 && !arg->size && arg->dot == 0)
	{
		ft_add_c_to_buff(arg, '0');
		return (1);
	}
	else if (nbr == 0 && arg->dot == 1)
	{
		if (!arg->size)
			return (0);
		else
		{
			ft_add_flag_spaces(arg, arg->size, arg->precision);
			return (arg->size);
		}
	}
	return (0);
}

int			ft_add_b(t_env *arg, size_t nbr)
{
	if (nbr == 0)
		return (ft_add_prc_zero_b(arg, nbr));
	arg->len = ft_nbrlen_binary(nbr);
	if (arg->flag[DIESE] && !arg->size && !arg->dot)
	{
		arg->len += ft_add_flag_diese(arg);
		ft_add_nbr_base(arg, nbr, BINARY);
		return (arg->len);
	}
	if (arg->size > arg->len && arg->precision <= arg->len)
		return (ft_add_size_b(arg, nbr));
	if (arg->precision >= arg->len && !arg->flag[LESS])
		return (ft_add_prc_b(arg, nbr));
	else if (arg->precision >= arg->len && arg->flag[LESS])
		return (ft_add_verify_prc_b(arg, nbr));
	ft_add_nbr_base(arg, nbr, BINARY);
	return (arg->len);
}
