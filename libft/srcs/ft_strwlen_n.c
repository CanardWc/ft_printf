/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 23:30:44 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 23:30:51 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strwlen_n(const wchar_t *s, int n)
{
	size_t	i;

	i = 0;
	if (s && n != 0)
	{
		while (*s != '\0' && n >= ft_wcharlen(*s))
		{
			n -= ft_wcharlen(*s);
			i += ft_wcharlen(*s);
			s++;
		}
	}
	return (i);
}
