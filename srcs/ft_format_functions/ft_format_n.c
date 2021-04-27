/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:34:59 by edassess          #+#    #+#             */
/*   Updated: 2021/04/27 15:21:26 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>
/*
int	ft_nbr_format(char *s, char *ref)
{
	char *format;
	int	ret;

	ret = 0;
	format = "cpdiusxXnfge%";
	while (*ref != '%')
		ref--;
	while (s < ref)
	{
		if (*s == '%')
		{
			ret++;
			s++;
			while (ft_strchr(format, *s))
				s++;
		}
	}
	return (ret);
}
*/
int	ft_format_n(t_printf data, t_flags flag, va_list ap)
{
	(void)flag;
	if (ft_search(data.s, "h") && *(ft_search(data.s, "h") - 1) == 'h')
		*(va_arg(ap, char *)) = data.ret;
	else if (ft_search(data.s, "h"))
		*(va_arg(ap, int *)) = data.ret;
	else if (ft_search(data.s, "l") && *(ft_search(data.s, "l") - 1) == 'l')
		*(va_arg(ap, long long int *)) = data.ret;
	else if (ft_search(data.s, "l"))
		*(va_arg(ap, long int *)) = data.ret;
	else
		*va_arg(ap, int *) = data.ret;
	return (data.ret);
}
