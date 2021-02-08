/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:08:16 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/08 17:26:00 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag_min(char *flag, char *str, char format)
{
	int		size;
	int		i;
	int		y;

	i = 0;
	while (flag[i] && flag[i] != '.')
		size = ft_atoi(strchr(flag, flag[i++])) > size ?\
		ft_atoi(strchr(flag, flag[i - 1])) : size;
	i = 0;
	while (!str[i] && i < size)
		i++;
	while (i >= 1)
	{
		y = 0;
		while (str[i + y])
		{
			str[(i + y) - 1] = str[i + y];
			y++;
		}
		if (y != 0)
			str[i + y - 1] = '\0';
		i--;
	}
	i = ft_strlen(str);
	while (i < size)
		str[i++] = ' ';
	return (str);
}
