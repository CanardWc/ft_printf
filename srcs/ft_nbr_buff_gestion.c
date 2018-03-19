/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_buff_gestion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 02:41:19 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 15:33:18 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_add_nbr_lng(t_env *arg, long long int n)
{
	if (n <= LONG_MIN)
	{
		ft_add_to_buff(arg, "-9223372036854775808");
		return ;
	}
	if (n < 0)
	{
		ft_add_c_to_buff(arg, '-');
		n = -n;
	}
	if (n > 9)
		ft_add_nbr_lng(arg, n / 10);
	ft_add_c_to_buff(arg, (n % 10 + '0'));
}

void	ft_add_nbr_hexa(t_env *arg, size_t nb)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= 16)
		ft_add_nbr_hexa(arg, nb / 16);
	ft_add_c_to_buff(arg, (str[nb % 16]));
}

void	ft_add_nbr_base(t_env *arg, unsigned long long int n, char *base)
{
	if (n >= ft_strlen(base))
		ft_add_nbr_base(arg, n / ft_strlen(base), base);
	ft_add_c_to_buff(arg, (base[n % ft_strlen(base)]));
}

void	ft_add_nbr(t_env *arg, int n)
{
	unsigned int	i;

	i = (unsigned int)n;
	if (n < 0)
	{
		ft_add_c_to_buff(arg, '-');
		i = -i;
	}
	if (i >= 10)
	{
		ft_add_nbr(arg, i / 10);
		ft_add_nbr(arg, i % 10);
	}
	else
		ft_add_c_to_buff(arg, (i + '0'));
}

void	ft_add_nbr_uns(t_env *arg, unsigned long long int n)
{
	if (n >= 10)
	{
		ft_add_nbr_uns(arg, n / 10);
		ft_add_c_to_buff(arg, ((n % 10) + '0'));
	}
	else
		ft_add_c_to_buff(arg, ((n % 10) + '0'));
}
