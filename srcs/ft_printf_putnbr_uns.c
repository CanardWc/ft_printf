/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_uns.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 03:02:17 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:36:00 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_putnbr_uns_octal(t_env *arg, size_t nbr)
{
	if (arg->modif[HH] == 1 && arg->conv != 'O')
		ft_add_nbr_base(arg, (unsigned char)nbr, OCTAL);
	else if (arg->modif[H] == 1 && arg->conv != 'O')
		ft_add_nbr_base(arg, (unsigned short int)nbr, OCTAL);
	else if (arg->modif[LL] == 1)
		ft_add_nbr_base(arg, nbr, OCTAL);
	else if (arg->modif[L] == 1 || arg->conv == 'O')
		ft_add_nbr_base(arg, (size_t)nbr, OCTAL);
	else if (arg->modif[J] == 1)
		ft_add_nbr_base(arg, (uintmax_t)nbr, OCTAL);
	else if (arg->modif[Z] == 1)
		ft_add_nbr_base(arg, (size_t)nbr, OCTAL);
	else
		ft_add_nbr_base(arg, nbr, OCTAL);
}

void	ft_printf_putnbr_uns_uns(t_env *arg, size_t nbr)
{
	if (arg->modif[HH] == 1 && arg->conv != 'U')
		ft_add_nbr(arg, (unsigned char)nbr);
	else if (arg->modif[H] == 1 && arg->conv != 'U')
		ft_add_nbr(arg, (unsigned short int)nbr);
	else if (arg->modif[LL] == 1)
		ft_add_nbr_uns(arg, nbr);
	else if (arg->modif[L] == 1 || arg->conv == 'U')
		ft_add_nbr_uns(arg, (size_t)nbr);
	else if (arg->modif[J] == 1)
		ft_add_nbr_uns(arg, (uintmax_t)nbr);
	else if (arg->modif[Z] == 1)
		ft_add_nbr_uns(arg, (size_t)nbr);
	else
		ft_add_nbr_uns(arg, nbr);
}

void	ft_printf_putnbr_uns_hexa_maj(t_env *arg, size_t nbr)
{
	if (arg->modif[HH] == 1)
		ft_add_nbr_base(arg, (unsigned char)nbr, MAJ_HEXA);
	else if (arg->modif[H] == 1)
		ft_add_nbr_base(arg, (unsigned short)nbr, MAJ_HEXA);
	else if (arg->modif[LL] == 1)
		ft_add_nbr_base(arg, nbr, MAJ_HEXA);
	else if (arg->modif[L] == 1)
		ft_add_nbr_base(arg, (unsigned long int)nbr, MAJ_HEXA);
	else if (arg->modif[J] == 1)
		ft_add_nbr_base(arg, (uintmax_t)nbr, MAJ_HEXA);
	else if (arg->modif[Z] == 1)
		ft_add_nbr_base(arg, (size_t)nbr, MAJ_HEXA);
	else
		ft_add_nbr_base(arg, nbr, MAJ_HEXA);
}

void	ft_printf_putnbr_uns_hexa_min(t_env *arg, size_t nbr)
{
	if (arg->modif[HH] == 1)
		ft_add_nbr_base(arg, (unsigned char)nbr, MIN_HEXA);
	else if (arg->modif[H] == 1)
		ft_add_nbr_base(arg, (unsigned short)nbr, MIN_HEXA);
	else if (arg->modif[LL] == 1)
		ft_add_nbr_base(arg, nbr, MIN_HEXA);
	else if (arg->modif[L] == 1)
		ft_add_nbr_base(arg, (unsigned long int)nbr, MIN_HEXA);
	else if (arg->modif[J] == 1)
		ft_add_nbr_base(arg, (uintmax_t)nbr, MIN_HEXA);
	else if (arg->modif[Z] == 1)
		ft_add_nbr_base(arg, (size_t)nbr, MIN_HEXA);
	else
		ft_add_nbr_base(arg, nbr, MIN_HEXA);
}

void	ft_printf_putnbr_uns(t_env *arg, size_t nbr)
{
	if (arg->conv == 'O' || arg->conv == 'o')
		return (ft_printf_putnbr_uns_octal(arg, nbr));
	if (arg->conv == 'U' || arg->conv == 'u')
		return (ft_printf_putnbr_uns_uns(arg, nbr));
	if (arg->conv == 'X')
		return (ft_printf_putnbr_uns_hexa_maj(arg, nbr));
	if (arg->conv == 'x')
		return (ft_printf_putnbr_uns_hexa_min(arg, nbr));
}
