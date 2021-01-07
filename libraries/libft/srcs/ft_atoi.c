/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:54:14 by fgrea             #+#    #+#             */
/*   Updated: 2020/11/28 14:02:46 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int	ret;
	int	neg;

	ret = 0;
	while (ft_isspace(*str))
		str++;
	neg = (*str == '-' ? -1 : 1);
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (ft_isdigit(*str))
		ret = (ret * 10) + (*str++ - 48);
	return (ret * neg);
}
