/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:46:53 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:34:17 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_flag(t_env *arg)
{
	if (arg->str[arg->cur] == '#')
	{
		arg->flag[DIESE] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '0')
	{
		arg->flag[ZERO] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '-')
	{
		arg->flag[LESS] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == '+')
	{
		arg->flag[MORE] = 1;
		arg->cur++;
	}
	else if (arg->str[arg->cur] == ' ')
	{
		arg->flag[SPACE] = 1;
		arg->cur++;
	}
}
