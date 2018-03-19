/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sgn_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:24:10 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:24:28 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_verify_size_sgn(t_env *arg, ssize_t nbr)
{
	arg->len += ft_add_flag_more(arg);
	arg->len += ft_add_flag_space(arg);
	ft_add_nbr_lng(arg, nbr);
	ft_add_flag_spaces(arg, arg->size, arg->len);
	return (arg->size);
}

static int	ft_add_size_sgn(t_env *arg, ssize_t nbr)
{
	if (arg->flag[ZERO] && !arg->dot)
	{
		arg->len += ft_add_flag_more(arg);
		arg->len += ft_add_flag_space(arg);
		arg->len += ft_add_flag_zero(arg, arg->size, arg->len);
	}
	else
	{
		if (arg->flag[MORE])
			arg->len++;
		ft_add_flag_spaces(arg, arg->size, arg->len);
		if (arg->flag[MORE])
			ft_add_to_buff(arg, "+");
	}
	ft_add_nbr_lng(arg, nbr);
	return (ft_nbcmp_max(arg->len, arg->size));
}

static int	ft_add_verify_prc_sgn(t_env *arg, ssize_t nbr)
{
	int	lenfin;

	lenfin = 0;
	if (arg->size > arg->precision)
	{
		lenfin += ft_add_flag_more(arg);
		lenfin += ft_add_flag_space(arg);
		ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_add_nbr_lng(arg, nbr);
		ft_add_flag_spaces(arg, arg->size, arg->precision + lenfin);
		return (arg->size);
	}
	else
	{
		lenfin += ft_add_flag_more(arg);
		lenfin += ft_add_flag_space(arg);
		lenfin += ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_add_nbr_lng(arg, nbr);
		arg->len += lenfin;
		return (ft_nbcmp_max(arg->len, arg->precision));
	}
	return (0);
}

static int	ft_add_prc_sgn(t_env *arg, ssize_t nbr)
{
	int		lenfin;

	lenfin = 0;
	if (arg->size > arg->precision)
	{
		if (arg->flag[MORE])
			lenfin = 1;
		ft_add_flag_spaces(arg, arg->size, arg->precision + lenfin);
		if (arg->flag[MORE])
			ft_add_to_buff(arg, "+");
		ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_add_nbr_lng(arg, nbr);
		return (arg->size);
	}
	else
	{
		lenfin += ft_add_flag_more(arg);
		lenfin += ft_add_flag_space(arg);
		lenfin += ft_add_flag_zero(arg, arg->precision, arg->len);
		ft_add_nbr_lng(arg, nbr);
		arg->len += lenfin;
	}
	return (ft_nbcmp_max(arg->len, arg->precision));
}

int			ft_add_sgn_pos(t_env *arg, ssize_t nbr)
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
