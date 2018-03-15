/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:36:38 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/14 15:59:31 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_buff_gestion(t_env *arg)
{
	if (arg->index == BUFF_SIZE)
	{
		ft_putstr(arg->buff);
		arg->index = 0;
	}
	if (arg->index == 0)
		ft_bzero(arg->buff, BUFF_SIZE);	
}

void		ft_add_to_buff(t_env *arg, char *s)
{
	char	*tmp;

	tmp = s;
	while (*tmp)
	{
		arg->buff[arg->index] = *tmp;
		*tmp++;
		arg->index++;
		ft_buff_gestion(arg);
	}
}
