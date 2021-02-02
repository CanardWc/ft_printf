/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:24:58 by edassess          #+#    #+#             */
/*   Updated: 2021/02/02 13:28:16 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int				ft_get_pow(long double fl)
{
	int			pow;

	pow = 0;
	if (fl < 1)
		while ((int)fl == 0)
		{
			fl *= 10.0;
			pow--;
		}
	else if (fl > 1)
		while ((long long int)fl > 9)
		{
			fl /= 10.0;
			pow++;
		}
	return (pow);
}

t_string		ft_format_size_e(long double nb, char *flags)
{
	t_string	ret;
	int			prec;
	int			sign;
	int			pow;

	ret.size = 0;
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) + 6 : 12;
	sign = nb < 0 ? -1 : 1;
	nb *= sign;
	pow = ft_get_pow(nb);
	prec = pow < 99 ? prec : prec++;
	if (ft_strchr(flags, '+') || ft_strchr(flags, ' ') || sign == -1)
		prec++;
	while (*flags && *flags != '.')
		ret.size = ret.size < ft_atoi(flags++) ? ft_atoi(flags - 1) : ret.size;
	ret.size = prec < ret.size && ret.size != 0 ? ret.size + 1 : prec + 1;
	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
		return (ret);
	return (ret);
}

long double		ft_get_ap_e(va_list ap, char *flags)
{
	if (ft_strchr(flags, 'l'))
		return ((long double)va_arg(ap, long double));
	else
		return ((long double)va_arg(ap, double));
}

int				ft_get_pow(long double v)
{
	int			pow;

	pow = 0;
	v = v < 0 ? v * -1 : v;
	if (v == 0)
		return (pow);
	if ((int)v > 0)
		while ((v /= 10) > 9)
			pow++;
	else
		while ((int)(v *= 10) == 0)
			pow--;
	return (pow);
}

char			*ft_format_e(va_list ap, char *flags, int i)
{
	t_string	ret;
	long double	prec;
	long double	v;
	int			size;
	int			pow;

	i = 0;
	v = ft_get_ap_e(v, flags);
	prec = ft_strchr(flags, '.') ? ft_atoi(ft_strchr(flags, '.') + 1) : 6;
	ret = ft_format_size_e(v, flags);
	size = ret.size - 1;
	pow = ft_get_pow(v);
	v = pow == 0 ? v : v * (10 * pow);
	while (pow > 9 || (pow /= 10) < 9)
		ret.str[--size] = pow % 10 + '0';
	ret.str[--size] = pow % 10 + '0';
	ret.str[--size] = pow < 0 ? '-' : ret.str[size];
	ret.str[pow < 0 ? --size : size] = 'e';
	v = prec > 0 ? v * (10 * prec) : v;
	while ((v /= 10) > 9)
		ret.str[--size] = v % 10 + '0';
	if (prec > 0)
		ret.str[--size] = '.';
	ret.str[--size] = v % 10 + '0';
	return (ret.str);
}
