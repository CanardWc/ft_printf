/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:01:14 by edassess          #+#    #+#             */
/*   Updated: 2021/02/02 12:24:14 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

double		ft_round_up(double nb, int prec, int pow)
{
	if (pow > 0 && ft_check_round_up_pos(nb, pow, prec))
		nb = ft_exp(10.0, pow + 1);

}

int			ft_format_size_g_e(double nb, int pow, int prec, char *flags)
{
	
}

int			ft_format_size_g_f(double nb, int pow, int prec, char *flags)
{
	
}

int			ft_format_size_g(double nb, char *flags)
{
	int		pow;
	int		sign;
	int		prec;
	char	*t_flags;

	ret = 0;
	pow = ft_get_pow(nb);
	prec = strchr(flags, '.') ? atoi(strchr(flags, '.') + 1) : 6;
	prec = prec == 0 ? 1 : prec;
	t_flags = flags;
	while (*t_flags && *t_flags != '.')
		ret = ret < atoi(flags++) ? atoi(flags - 1) : ret;
	sign = nb >= 0.0 ? 1 : -1;
	nb *= sign;
	nb = ft_round(nb, prec, pow);
	if (pow > 0)
		return (pow >= prec || pow < -4 ? ft_format_size_g_e(nb, pow, prec, flags) : \
				ft_format_size_g_e(nb, pow, prec, flags));
}
