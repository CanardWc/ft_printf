/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:00:13 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:34:49 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_take_precision(t_env *arg)
{
	char	*str;
	int		i;

	i = 0;
	while (ft_isdigit(arg->str[i]) && arg->str[i] != '\0')
		i++;
	if (!(str = ft_strnew(i)))
		return ;
	i = 0;
	while (ft_isdigit(arg->str[arg->cur]) && arg->str[i] != '\0')
	{
		str[i] = arg->str[arg->cur];
		arg->cur++;
		i++;
	}
	str[i] = '\0';
	arg->precision = ft_atoi(str);
	free(str);
}

void	ft_parse_precision(t_env *arg)
{
	int		i;

	i = 0;
	arg->dot = 1;
	if (arg->str[arg->cur] == '.')
	{
		arg->dot = 1;
		arg->cur++;
	}
	else
	{
		arg->dot = 0;
		return ;
	}
	if (arg->str[arg->cur] == '-' || !(ft_isdigit(arg->str[arg->cur])))
	{
		arg->precision = 0;
		return ;
	}
	ft_take_precision(arg);
}
