/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 23:30:12 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 23:30:14 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putwstr_n(wchar_t *s, int n)
{
	if (s && n != 0)
	{
		while (*s != '\0' && n > 0)
		{
			if (n >= ft_wcharlen(*s))
				ft_putwchar(*s);
			n -= ft_wcharlen(*s);
			s++;
		}
	}
}
