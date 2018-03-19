/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_caste_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 03:09:40 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:27:08 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_caste_uns_octal(t_env *arg, va_list ap)
{
	ssize_t cast;

	cast = 0;
	if (arg->conv == 'O')
		return (ft_add_octal(arg, va_arg(ap, unsigned long)));
	else if (arg->modif[Z] == 1)
		return (ft_add_octal(arg, va_arg(ap, size_t)));
	else if (arg->modif[LL] == 1)
		return (ft_add_octal(arg, va_arg(ap, size_t)));
	else if (arg->modif[J] == 1)
		return (ft_add_octal(arg, va_arg(ap, uintmax_t)));
	else if (arg->modif[L] == 1)
		return (ft_add_octal(arg, va_arg(ap, unsigned long)));
	else if (arg->modif[H] == 1)
	{
		cast = va_arg(ap, unsigned int);
		return (ft_add_octal(arg, (unsigned short)cast));
	}
	else if (arg->modif[HH] == 1)
	{
		cast = va_arg(ap, unsigned int);
		return (ft_add_octal(arg, (unsigned char)cast));
	}
	else
		return (ft_add_octal(arg, va_arg(ap, unsigned)));
}

int	ft_caste_uns_uns(t_env *arg, va_list ap)
{
	ssize_t cast;

	cast = 0;
	if (arg->conv == 'U')
		return (ft_add_uns(arg, va_arg(ap, unsigned long)));
	else if (arg->modif[Z] == 1)
		return (ft_add_uns(arg, va_arg(ap, size_t)));
	else if (arg->modif[LL] == 1)
		return (ft_add_uns(arg, va_arg(ap, size_t)));
	else if (arg->modif[J] == 1)
		return (ft_add_uns(arg, va_arg(ap, uintmax_t)));
	else if (arg->modif[L] == 1)
		return (ft_add_uns(arg, va_arg(ap, unsigned long)));
	else if (arg->modif[H] == 1)
	{
		cast = va_arg(ap, unsigned int);
		return (ft_add_uns(arg, (unsigned short)cast));
	}
	else if (arg->modif[HH] == 1)
	{
		cast = va_arg(ap, unsigned int);
		return (ft_add_uns(arg, (unsigned char)cast));
	}
	else
		return (ft_add_uns(arg, va_arg(ap, unsigned)));
}

int	ft_caste_uns_hexa(t_env *arg, va_list ap)
{
	ssize_t cast;

	cast = 0;
	if (arg->modif[Z] == 1)
		return (ft_add_hexa(arg, va_arg(ap, size_t)));
	else if (arg->modif[LL] == 1)
		return (ft_add_hexa(arg, va_arg(ap, size_t)));
	else if (arg->modif[J] == 1)
		return (ft_add_hexa(arg, va_arg(ap, uintmax_t)));
	else if (arg->modif[L] == 1)
		return (ft_add_hexa(arg, va_arg(ap, unsigned long)));
	else if (arg->modif[H] == 1)
	{
		cast = va_arg(ap, unsigned int);
		return (ft_add_hexa(arg, (unsigned short)cast));
	}
	else if (arg->modif[HH] == 1)
	{
		cast = va_arg(ap, unsigned int);
		return (ft_add_hexa(arg, (unsigned char)cast));
	}
	else
		return (ft_add_hexa(arg, va_arg(ap, unsigned)));
}

int	ft_caste_uns_binary(t_env *arg, va_list ap)
{
	ssize_t cast;

	cast = 0;
	if (arg->modif[Z] == 1)
		return (ft_add_b(arg, va_arg(ap, size_t)));
	else if (arg->modif[LL] == 1)
		return (ft_add_b(arg, va_arg(ap, size_t)));
	else if (arg->modif[J] == 1)
		return (ft_add_b(arg, va_arg(ap, uintmax_t)));
	else if (arg->modif[L] == 1)
		return (ft_add_b(arg, va_arg(ap, unsigned long)));
	else if (arg->modif[H] == 1)
	{
		cast = va_arg(ap, unsigned int);
		return (ft_add_b(arg, (unsigned short)cast));
	}
	else if (arg->modif[HH] == 1)
	{
		cast = va_arg(ap, unsigned int);
		return (ft_add_b(arg, (unsigned char)cast));
	}
	else
		return (ft_add_b(arg, va_arg(ap, unsigned)));
}

int	ft_caste_uns(t_env *arg, va_list ap)
{
	if (arg->conv == 'O' || arg->conv == 'o')
		return (ft_caste_uns_octal(arg, ap));
	else if (arg->conv == 'U' || arg->conv == 'u')
		return (ft_caste_uns_uns(arg, ap));
	else if (arg->conv == 'X' || arg->conv == 'x')
		return (ft_caste_uns_hexa(arg, ap));
	else if (arg->conv == 'b')
		return (ft_caste_uns_binary(arg, ap));
	return (0);
}
