/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:42:47 by edassess          #+#    #+#             */
/*   Updated: 2021/02/04 11:13:45 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

t_string				ft_format_size_x(int nb, char *flags)
{
	t_string	ret;
	char		*tmp;
	int			t_ret;

	tmp = flags;
	ret.size = 1;
	while ((nb /= 16) > 0)
		ret.size++;
	t_ret = ret.size;
	while (*flags && *flags != '.')
		ret.size = ret.size < ft_atoi(flags++) ? ft_atoi(flags - 1) : ret.size;
	if (ft_strchr(tmp, '#') && t_ret + 1 >= ret.size)
		ret.size = t_ret + 2;
	if (ft_strchr(tmp, '.') && ft_atoi(ft_strchr(tmp, '.') + 1) >= ret.size)
		if (ft_strchr(tmp, '#'))
			ret.size += 2;
	ret.size++;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret);
	return (ret);
}

unsigned long long int	ft_get_ap_x(va_list ap, char *flags)
{
	if (ft_strchr(flags, 'l') && *(ft_strchr(flags, 'l') + 1) == 'l')
		return (va_arg(ap, unsigned long long int));
	else if (ft_strchr(flags, 'l'))
		return ((unsigned long long int)va_arg(ap, unsigned long int));
	else if (ft_strchr(flags, 'h') && *(ft_strchr(flags, 'h') + 1) == 'h')
		return ((unsigned long long int)va_arg(ap, unsigned int));
	else if (ft_strchr(flags, 'h'))
		return ((unsigned long long int)va_arg(ap, unsigned int));
	else
		return ((unsigned long long int)va_arg(ap, unsigned int));
}

char					*ft_format_x(va_list ap, char *flags, int i)
{
	char			*base;
	t_string		ret;
	int				prec;
	int				size;
	unsigned int	v;

	base = "0123456789abcdef";
	i = 0;
	v = ft_get_ap_x(ap, flags);
	ret = ft_format_size_x(v, flags);
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) : 0;
	size = ret.size - 1;
	prec = prec < 0 ? -1 : prec;
	while (v > 15)
	{
		ret.str[--size] = base[v % 16];
		v /= 16;
		prec--;
	}
	ret.str[--size] = base[v % 16];
	while (--prec > 0)
		ret.str[--size] = '0';
	return (ret.str);
}
