/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:40:05 by edassess          #+#    #+#             */
/*   Updated: 2021/02/08 13:50:05 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_string	ft_format_size_s(char *s, char *flags)
{
	t_string	ret;
	int			prec;

	ret.size = 0;
	prec = ft_strchr(flags, '.') ? \
		ft_atoi(ft_strchr(flags, '.') + 1) : ft_strlen(s);
	prec = prec > (int)ft_strlen(s) ? (int)ft_strlen(s) : prec;
	while (*flags && *flags != '.')
		ret.size = ft_atoi(flags++) > ret.size ? ft_atoi(flags - 1) : ret.size;
	ret.size = ret.size < prec ? prec + 1 : ret.size + 1;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret);
	return (ret);
}

char		*ft_format_s(va_list ap, char *flags, int i)
{
	t_string	ret;
	char		*s;
	int			v;

	i = 0;
	s = va_arg(ap, char *);
	ret = ft_format_size_s(s, flags);
	v = 0;
	while (v < ret.size - 1)
		ret.str[v++] = *s++;
	return (ret.str);
}
