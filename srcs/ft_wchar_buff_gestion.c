/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_buff_gestion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 01:08:36 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:52:30 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_add_wstr(t_env *arg, wchar_t const *str)
{
	while (*str)
		ft_add_wchar(arg, *str++);
}

void	ft_add_wchar(t_env *arg, wchar_t c)
{
	if (c <= 0x7F)
		ft_add_c_to_buff(arg, c);
	else if (c <= 0x7FF)
	{
		ft_add_c_to_buff(arg, (c >> 6) | 0xC0);
		ft_add_c_to_buff(arg, (c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		ft_add_c_to_buff(arg, (c >> 12) | 0xE0);
		ft_add_c_to_buff(arg, ((c >> 6) & 0x3F) | 0x80);
		ft_add_c_to_buff(arg, (c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		ft_add_c_to_buff(arg, (c >> 18) | 0xF0);
		ft_add_c_to_buff(arg, ((c >> 12) & 0x3F) | 0x80);
		ft_add_c_to_buff(arg, ((c >> 6) & 0x3F) | 0x80);
		ft_add_c_to_buff(arg, (c & 0x3F) | 0x80);
	}
}

void	ft_add_wstr_n(t_env *arg, wchar_t *s, int n)
{
	if (s && n != 0)
	{
		while (*s != '\0' && n > 0)
		{
			if (n >= ft_wcharlen(*s))
				ft_add_wchar(arg, *s);
			n -= ft_wcharlen(*s);
			s++;
		}
	}
}
