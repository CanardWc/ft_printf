/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caste_sgn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 01:52:41 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:26:32 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_caste_sgn(t_env *arg, va_list ap)
{
	ssize_t cast;

	cast = 0;
	if (arg->conv == 'D')
		return (ft_add_sgn(arg, va_arg(ap, signed long int)));
	if (arg->modif[Z] == 1)
		return (ft_add_sgn(arg, va_arg(ap, size_t)));
	if (arg->modif[LL] == 1)
		return (ft_add_sgn(arg, va_arg(ap, signed long long int)));
	if (arg->modif[J] == 1)
		return (ft_add_sgn(arg, va_arg(ap, intmax_t)));
	if (arg->modif[L] == 1)
		return (ft_add_sgn(arg, va_arg(ap, signed long int)));
	if (arg->modif[H] == 1)
	{
		cast = va_arg(ap, signed int);
		return (ft_add_sgn(arg, (short int)cast));
	}
	if (arg->modif[HH] == 1)
	{
		cast = va_arg(ap, signed int);
		return (ft_add_sgn(arg, (signed char)cast));
	}
	else
		return (ft_add_sgn(arg, va_arg(ap, signed int)));
}
