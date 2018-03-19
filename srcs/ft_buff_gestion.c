/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_gestion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:36:38 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 23:32:00 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_buff_gestion(t_env *arg)
{
	if (arg->index == BUFFER_SIZE)
	{
		ft_putstr_n(arg->buff, arg->index);
		arg->index = 0;
	}
	if (arg->index == 0)
		ft_bzero(arg->buff, BUFFER_SIZE);
}

void		ft_add_to_buff(t_env *arg, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		arg->buff[arg->index] = s[i];
		i++;
		arg->index++;
		ft_buff_gestion(arg);
	}
}

void		ft_add_c_to_buff(t_env *arg, char c)
{
	arg->buff[arg->index] = c;
	arg->index++;
	ft_buff_gestion(arg);
}

void		ft_buff_final(t_env *arg)
{
	if (arg->index != 0)
		ft_putstr_n(arg->buff, arg->index);
}
