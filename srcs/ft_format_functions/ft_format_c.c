/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:21:15 by edassess          #+#    #+#             */
/*   Updated: 2021/02/02 13:21:17 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>

t_string	ft_format_size_c(char *flags)
{
	t_string	ret;

	ret.size = 0;
	while (*flags != '.' && *flags)
		ret.size = ft_atoi(flags++) < ret.size ? ret.size : \
			   ft_atoi(flags - 1);
	ret.size = ret.size == 0 ? 2 : ret.size + 1;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret);
	return (ret);
}

char		*ft_format_c(va_list ap, char *flags, int i)
{
	t_string	ret;

	i = 0;
	ret = ft_format_size_c(flags);
	flags = (void *)flags;
	ret.str[0] = (unsigned char)va_arg(ap, int);
	return (ret.str);
}
