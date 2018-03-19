/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 23:30:36 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 23:30:40 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strwlen(const wchar_t *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((int)s[i] < 0x7F)
			j += 1;
		else if ((int)s[i] < 0x7FF)
			j += 2;
		else if ((int)s[i] < 0xFFFF)
			j += 3;
		else if ((int)s[i] < 0x10FFFF)
			j += 4;
		i++;
	}
	return (j);
}
