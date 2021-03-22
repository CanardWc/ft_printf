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

const char	*hash[] = { "0x", "0x", "0X", "0" };
/*
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
*/

void	ft_flag_hash(char format)
{
	char	*form = "pxXo";
	char	*good_hash;
	
	good_hash = (char *)hash[ft_strchr(form, format) - form];
	if (ft_strchr(form, format))
		ft_putstr_fd(good_hash, 1);
}
