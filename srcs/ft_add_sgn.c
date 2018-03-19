/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sgn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:22:55 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:22:40 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_flag_sgn(t_env *arg, ssize_t nbr)
{
	arg->len += ft_add_flag_more(arg);
	arg->len += ft_add_flag_space(arg);
	ft_add_nbr_lng(arg, nbr);
	return (arg->len);
}

static int	ft_add_prc_zero_sgn(t_env *arg)
{
	if (!arg->size)
		return (0);
	else
	{
		ft_add_flag_spaces(arg, arg->size, arg->precision);
		return (arg->size);
	}
}

int			ft_add_sgn(t_env *arg, ssize_t nbr)
{
	arg->len = ft_nbrlen(nbr);
	if (nbr == 0 && arg->dot == 1 && arg->precision == 0)
		return (ft_add_prc_zero_sgn(arg));
	if (nbr >= 0 && (arg->flag[MORE] || arg->flag[SPACE]) &&
	!arg->flag[LESS] && arg->size < arg->len && !arg->dot)
		return (ft_add_flag_sgn(arg, nbr));
	return (nbr >= 0 ? ft_add_sgn_pos(arg, nbr) : ft_add_sgn_neg(arg, nbr));
}
