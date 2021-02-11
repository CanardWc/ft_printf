/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_spc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:54:09 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/10 14:54:24 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

char	*ft_flag_spc(char *flag, char *str, char format)
{
	int i;

	(void)flag;
	i = 0;
	if (!(format == 'd' || format == 'i' || format == 'e' \
				|| format == 'f' || format == 'g'))
		return (str);
	while (!str[i] || str[i] == ' ')
		i++;
	if (str[i] != '-')
		str[i - 1] = ' ';
	return (str);
}
