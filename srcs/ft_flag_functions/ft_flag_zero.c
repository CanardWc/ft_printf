/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:54:35 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/02 16:15:00 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_zero(char *flag, char *str, char format)
{
	int		size;
	int		i;
	int		neg;

	i = 0;
	while (flag[i] && flag[i] != '.')
		size = ft_atoi(strchr(flag, flag[i++])) > size ?\
			ft_atoi(strchr(flag, flag[i - 1])) : size;
	i = 0;
	while (!str[i] && i < size)
		i++;
	neg = (format == 'i' || format == 'd') && str[i] == '-' ? 1 : 0;
	i += (int)ft_strlen(str + i) - 1;
	while (str[i] && i > 0)
	{
		str[size--] = str[i];
		str[i--] = '\0';
	}
	i = 0;
	while (!str[i])
		str[i++] = '0';
	str[0] = neg ? '-' : '0';
	str[i] = neg ? '0' : str[i];
	str[1] = format == 'p' ? 'x' : str[1];
	str[i + 1] = format == 'p' ? '0' : str[i + 1];
	return (str);
}
