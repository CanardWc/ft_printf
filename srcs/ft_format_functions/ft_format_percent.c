/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:39:50 by edassess          #+#    #+#             */
/*   Updated: 2021/02/04 11:14:02 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_string	ft_format_size_percent(char *flags)
{
	t_string	ret;

	ret.size = 2;
	while (*flags && *flags != '.')
		ret.size = ft_atoi(flags++) > \
				ret.size ? ft_atoi(flags - 1) + 1 : ret.size;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret);
	return (ret);
}

char		*ft_format_percent(va_list ap, char *flags, int i)
{
	t_string	ret;

	i = 0;
	ap = (void *)ap;
	flags = (void *)flags;
	ret = ft_format_size_percent(flags);
	ret.str[0] = '%';
	return (ret.str);
}
