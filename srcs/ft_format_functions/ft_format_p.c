/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:38:16 by edassess          #+#    #+#             */
/*   Updated: 2021/02/02 13:39:06 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_string	ft_format_size_p(unsigned long int nb, char *flags)
{
	t_string		ret;
	int				i;
	int				prec;

	flags = (void *)flags;
	ret.size = 0;
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) : 0;
	i = 1;
	while ((nb = nb >> 4) > 0)
		i++;
	while (*flags && *flags != '.')
		ret.size = ft_atoi(flags++) > ret.size ? ft_atoi(flags - 1) : ret.size;
	i = prec > i ? prec : i;
	ret.size = ret.size < i + 2 ? i + 3 : ret.size + 1;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret);
	return (ret);
}

char		*ft_format_p(va_list ap, char *flags, int i)
{
	char				*base;
	t_string			ret;
	int					size;
	unsigned long int	v;

	base = "0123456789abcdef";
	i = 0;
	v = va_arg(ap, unsigned long int);
	flags = (void *)flags;
	ret = ft_format_size_p(v, flags);
	size = ret.size - 1;
	while (v > 15)
	{
		ret.str[--size] = base[v % 16];
		v = v >> 4;
	}
	ret.str[--size] = base[v % 16];
	return (ret.str);
}
