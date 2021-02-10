/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:56:45 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/10 14:49:47 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

char	*ft_flag_hash_g(char *str, int size)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (!str[i])
		i++;
	while (str[i])
	{
		str[y++] = str[i];
		str[i++] = '\0';
	}
	i = 0;
	while (i < 7)
		if (str[i++] == '\0')
			str[i - 1] = '0';
	i = 0;
	y = size - 7;
	while (str[i])
	{
		str[y++] = str[i];
		str[i++] = '\0';
	}
	return (str);
}

char	*ft_flag_hash_x(char *str)
{
	int i;

	i = 0;
	while (!str[i])
		i++;
	str[i - 1] = 'x';
	str[i - 2] = '0';
	return (str);
}

char	*ft_flag_hash_bigx(char *str)
{
	int i;

	i = 0;
	while (!str[i])
		i++;
	str[i - 1] = 'X';
	str[i - 2] = '0';
	return (str);
}

char	*ft_flag_hash(char *flag, char *str, char format)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (flag[i] && flag[i] != '.')
		size = ft_atoi(ft_strchr(flag, flag[i++])) > size ? \
		ft_atoi(ft_strchr(flag, flag[i - 1])) : size;
	if (format == 'g')
		return (ft_flag_hash_g(str, size));
	if (format == 'x')
		return (ft_flag_hash_x(str));
	if (format == 'X')
		return (ft_flag_hash_bigx(str));
	return (str);
}
