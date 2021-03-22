/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:34:59 by edassess          #+#    #+#             */
/*   Updated: 2021/02/02 13:35:01 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int	ft_format_n(va_list ap, const char *s, int i)
{
	if (ft_search(s, "h") && *(ft_search(s, "h") - 1) == 'h')
		*(va_arg(ap, char *)) = i + 1;
	else if (ft_search(s, "h"))
		*(va_arg(ap, int *)) = i + 1;
	else if (ft_search(s, "l") && *(ft_search(s, "l") - 1) == 'l')
		*(va_arg(ap, long long int *)) = i + 1;
	else if (ft_search(s, "l"))
		*(va_arg(ap, long int *)) = i + 1;
	else
		*va_arg(ap, int *) = i + 1;
	return (i);
}
