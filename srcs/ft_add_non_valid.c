/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_non_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:21:07 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:19:58 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_verify_size_non_valid(t_env *arg, char c)
{
	ft_add_c_to_buff(arg, c);
	ft_add_flag_spaces(arg, arg->size, arg->len);
	return (arg->size);
}

static int	ft_add_size_non_valid(t_env *arg, char c)
{
	if (arg->flag[LESS])
		return (ft_add_verify_size_non_valid(arg, c));
	else
	{
		if (arg->flag[ZERO])
			ft_add_flag_zero(arg, arg->size, arg->len);
		else
			ft_add_flag_spaces(arg, arg->size, arg->len);
		ft_add_c_to_buff(arg, c);
	}
	return (arg->size);
}

int			ft_add_non_valid(t_env *arg)
{
	unsigned char	c;

	c = arg->conv;
	arg->len = 1;
	if (arg->size > 1 && (!arg->dot || arg->dot))
		return (ft_add_size_non_valid(arg, c));
	ft_add_c_to_buff(arg, c);
	return (1);
}
