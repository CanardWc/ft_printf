/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 05:20:17 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:41:04 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_add_flag_diese(t_env *arg)
{
	if (arg->flag[DIESE])
	{
		if (arg->conv == 'x')
		{
			ft_add_to_buff(arg, "0x");
			return (2);
		}
		else if (arg->conv == 'X')
		{
			ft_add_to_buff(arg, "0X");
			return (2);
		}
		else if (arg->conv == 'o' || arg->conv == 'O')
		{
			ft_add_c_to_buff(arg, '0');
			return (1);
		}
		else if (arg->conv == 'b')
		{
			ft_add_to_buff(arg, "0x");
			return (2);
		}
	}
	return (0);
}

int	ft_add_flag_more(t_env *arg)
{
	if (arg->flag[MORE])
	{
		ft_add_c_to_buff(arg, '+');
		return (1);
	}
	return (0);
}

int	ft_add_flag_space(t_env *arg)
{
	if (arg->flag[SPACE] == 1 && arg->flag[MORE] != 1)
	{
		ft_add_c_to_buff(arg, ' ');
		return (1);
	}
	return (0);
}

int	ft_add_flag_zero(t_env *arg, int start, int end)
{
	int i;

	i = 0;
	while (i < start - end)
	{
		ft_add_c_to_buff(arg, '0');
		i++;
	}
	return (i);
}

int	ft_add_flag_spaces(t_env *arg, int start, int end)
{
	int i;

	i = 0;
	while (i < start - end)
	{
		ft_add_c_to_buff(arg, ' ');
		i++;
	}
	return (i);
}
