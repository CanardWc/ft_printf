/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sgn_neg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:23:30 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:23:56 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_verify_size_sgn(t_env *arg, ssize_t nbr)
{
	ft_add_nbr_lng(arg, nbr);
	arg->len += ft_add_flag_spaces(arg, arg->size, arg->len);
	return (arg->size);
}

static int	ft_add_size_sgn(t_env *arg, ssize_t nbr)
{
	if (arg->flag[ZERO])
	{
		ft_add_c_to_buff(arg, '-');
		arg->len += ft_add_flag_zero(arg, arg->size, arg->len);
	}
	else
		ft_add_flag_spaces(arg, arg->size, arg->len);
	if (arg->flag[ZERO])
		ft_add_nbr_lng(arg, ft_abs(nbr));
	else
		ft_add_nbr_lng(arg, nbr);
	return (ft_nbcmp_max(arg->len, arg->size));
}

static int	ft_add_verify_prc_sgn(t_env *arg, ssize_t nbr)
{
	ft_add_c_to_buff(arg, '-');
	ft_add_flag_zero(arg, arg->precision, arg->len + 1);
	ft_add_nbr_lng(arg, ft_abs(nbr));
	return (ft_nbcmp_max(arg->precision, arg->len));
}

static int	ft_add_prc_sgn(t_env *arg, ssize_t nbr)
{
	if (arg->size > arg->precision)
	{
		ft_add_flag_spaces(arg, arg->size, arg->precision + 1);
		ft_add_c_to_buff(arg, '-');
		ft_add_flag_zero(arg, arg->precision, arg->len - 1);
		ft_add_nbr_lng(arg, ft_abs(nbr));
		return (arg->size);
	}
	else
	{
		ft_add_c_to_buff(arg, '-');
		arg->len += ft_add_flag_zero(arg, arg->precision, arg->len - 1);
		ft_add_nbr_lng(arg, ft_abs(nbr));
		return (ft_nbcmp_max(arg->len, arg->precision));
	}
	return (0);
}

int			ft_add_sgn_neg(t_env *arg, ssize_t nbr)
{
	if (arg->size > arg->len && arg->precision <= arg->len &&
			!arg->flag[LESS])
		return (ft_add_size_sgn(arg, nbr));
	if (arg->size > arg->len && arg->precision <= arg->len &&
			arg->flag[LESS])
		return (ft_add_verify_size_sgn(arg, nbr));
	if (arg->precision >= arg->len && !arg->flag[LESS])
		return (ft_add_prc_sgn(arg, nbr));
	else if (arg->precision >= arg->len && arg->flag[LESS])
		return (ft_add_verify_prc_sgn(arg, nbr));
	ft_add_nbr_lng(arg, nbr);
	return (arg->len);
}
