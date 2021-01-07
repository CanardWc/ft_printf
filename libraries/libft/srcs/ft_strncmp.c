/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:08:50 by fgrea             #+#    #+#             */
/*   Updated: 2020/11/28 11:48:31 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	return ((*s1 && *s2 && *s1 == *s2 && n > 0) ? \
		ft_strncmp(++s1, ++s2, --n) : \
		(unsigned char)(*s1) - (unsigned char)(*s2));
}
