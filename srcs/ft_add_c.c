/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:19:47 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:13:43 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_add_verify_size_c(t_env *arg, char c)
{
	ft_add_c_to_buff(arg, c);
	ft_add_flag_spaces(arg, arg->size, 1);
	return (arg->size);
}

static int	ft_add_size_c(t_env *arg, char c)
{
	if (arg->flag[LESS])
		return (ft_add_verify_size_c(arg, c));
	else
	{
		if (arg->flag[ZERO])
			arg->len += ft_add_flag_zero(arg, arg->size, arg->len);
		else
			ft_add_flag_spaces(arg, arg->size, 1);
		ft_add_c_to_buff(arg, c);
	}
	return (arg->size);
}

int			ft_add_c(t_env *arg, va_list ap)
{
	unsigned char	c;

	if (arg->modif[L] == 1)
		return (ft_add_wc(arg, ap));
	else
		c = va_arg(ap, int);
	arg->len = 1;
	if (arg->size > arg->len && (!arg->dot || arg->dot))
		return (ft_add_size_c(arg, c));
	ft_add_c_to_buff(arg, c);
	return (1);
}
