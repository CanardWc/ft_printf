/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:24:27 by edassess          #+#    #+#             */
/*   Updated: 2021/05/05 14:07:30 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>

const t_form_f	g_form_fct[] = {
	{'c', &ft_format_c}, {'s', &ft_format_s}, \
	{'p', &ft_format_uint}, {'d', &ft_format_int}, \
	{'i', &ft_format_int}, {'u', &ft_format_uint}, \
	{'o', &ft_format_uint}, {'x', &ft_format_uint}, \
	{'X', &ft_format_uint}, {'n', &ft_format_n}, \
	{'f', &ft_format_f}, {'g', &ft_format_g}, \
	{'e', &ft_format_e}, {'%', &ft_format_percent}};

static t_printf	ft_format_treatment(t_printf data, va_list ap)
{
	char	*format_list;
	int		k;
	t_flags	flags;

	format_list = "cspdiuoxXnfge%";
	k = 0;
	flags = ft_flag_asterisk(data.s, ap);
	data.s++;
	while (*(data.s) && ft_strchr("-.*lh# +0123456789$", *(data.s)))
		data.s++;
	if (*(data.s) && ft_strchr(format_list, *(data.s)))
	{
		while (g_form_fct[k].format != *ft_strchr(format_list, *(data.s)))
			k++;
		data.ret = g_form_fct[k].fct(data, flags, ap);
		data.s++;
	}
	return (data);
}

int	ft_printf(const char *s, ...)
{
	t_printf	data;
	va_list		ap;

	data.s = s;
	data.ret = 0;
	va_start(ap, s);
	while (*(data.s))
	{
		if (*(data.s) == '%')
			data = ft_format_treatment(data, ap);
		else
		{
			ft_putchar_fd(*data.s++, 1);
			data.ret++;
		}
	}
	data.s = NULL;
	s = NULL;
	va_end(ap);
	return (data.ret);
}
