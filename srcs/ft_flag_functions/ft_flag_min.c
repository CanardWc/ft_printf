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

int	ft_flag_min(t_flags flags, int size)
{
	int	ret;

<<<<<<< HEAD
	ret = flags.min - size;
	while (flags.min-- > size)
		ft_putchar_fd(' ', 1);
=======
	(void)format;
	i = 0;
	ret = str;
	while (!ft_isdigit(flag[i]) && flag[i] != '.' && flag[i])
		i++;
	size = ft_atoi(flag + i);
	o_size = size;
	i = 0;
	while (!str[i] && size-- > 0)
		i++;
	o_size -= ft_strlen(str + i) ? ft_strlen(str + i) : 0;
	while (*(str++ + i))
		*(str - 1) = str[i - 1];
	while (o_size-- > 0)
		*(str++ - 1) = ' ';
>>>>>>> 57a9b3f9e648fd19df093a2119cfda09e300de6d
	return (ret);
}
