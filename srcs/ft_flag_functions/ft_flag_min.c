/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2021/02/10 14:51:13 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>


char	*ft_flag_minus(char *flag, char *str, char format)
{
	int		size;
	int		i;
	int		y;

	(void)format;
	i = 0;
	while (flag[i] && flag[i] != '.')
		size = ft_atoi(ft_strchr(flag, flag[i++])) > size ?\
		ft_atoi(ft_strchr(flag, flag[i - 1])) : size;
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
