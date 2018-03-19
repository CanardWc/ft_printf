/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:35:03 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 19:38:26 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_reader(t_env *arg, va_list ap)
{
	size_t	len;

	len = 0;
	while (arg->str[arg->cur] != '\0')
	{
		if (arg->str[arg->cur] == '%')
		{
			arg->cur++;
			arg->ret = ft_parse(arg);
			if (arg->ret == 1)
				len += ft_add_arg(arg, ap);
			if (!arg->conv && arg->conv != '%' && arg->ret == 1)
				return (0);
		}
		else
		{
			ft_add_c_to_buff(arg, (arg->str[arg->cur]));
			arg->cur++;
			len++;
		}
	}
	return (len + arg->printcar);
}
