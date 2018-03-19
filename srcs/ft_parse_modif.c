/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_modif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:53:33 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:34:31 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_modif(t_env *arg)
{
	if (arg->str[arg->cur] == 'h' && arg->str[arg->cur + 1] == 'h')
	{
		arg->modif[HH] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == 'h')
		arg->modif[H] = 1;
	else if (arg->str[arg->cur] == 'l' && arg->str[arg->cur + 1] == 'l')
	{
		arg->modif[LL] = 1L;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == 'l')
		arg->modif[L] = 1;
	else if (arg->str[arg->cur] == 'j')
		arg->modif[J] = 1;
	else if (arg->str[arg->cur] == 'z')
		arg->modif[Z] = 1;
	arg->cur++;
}
