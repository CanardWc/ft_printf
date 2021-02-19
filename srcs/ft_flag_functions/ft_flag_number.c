/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:13:31 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/10 14:55:46 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static char *place_space(char *str ,int i)
{
	int	j;

	if (str[i])
	{
		j = ft_strlen(str + i) + 1;
		while (--j > 0)
			str[i + j] = str[i + j - 1];
	}
	str[i] = ' ';
	return(str);
}

char	*ft_flag_number(char *flag, char *str, char format)
{
	int	o_size;
	int 	size;
	int	i;

	(void)format;
	o_size = 0;
	i = 0;
	size = ft_atoi(flag);
	while (!str[i] && size-- > 0)
		i++;
	while (str[i++])
		o_size++;
	o_size = o_size ? o_size : 1;
	i = 0;
	size = ft_atoi(flag) - o_size;
	while (i < size)
		str = place_space(str, i++);
	return(str);
}
