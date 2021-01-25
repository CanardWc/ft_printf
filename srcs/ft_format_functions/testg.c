/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:46:41 by edassess          #+#    #+#             */
/*   Updated: 2021/01/25 17:01:07 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int ft_get_pow(long double fl)
{
	int pow;

	pow = 0;
	if (fl < 1.0)
		while((int)fl == 0)
		{
			fl *= 10.0;
			pow--;
		}
	else if (fl > 1.0)
		while((int)fl > 9)
		{
			fl /= 10.0;
			pow++;
		}
	return(pow);
}


int		ft_ignore_zero(int nb, int prec, int pow)
{
	int		i;

	i = 0;
	if (nb < 1 && (pow *= -1) != -1)
		while ((pow + 1 - prec) > i)
		{
			nb *= 10;
			i++;
		}
	else
		while ((pow + 1 - prec) > i)
		{
			nb /= 10;
			i++;
		}
	i = 0;
	while ((nb % 10) == 0)
	{
		i++;
		nb /= 10;
	}
	return (prec - i);
}

int		ft_size_g_e(char *flags, double nb, int pow, int sign)
{
	int		ret;
	int		prec;
	char	*t_flags;

	ret = 0;
	if (!strchr(flags, '.'))
		prec = 6;
	else
		prec = atoi(strchr(flags, '.') + 1) == 0 ? 1 : atoi(strchr(flags, '.') + 1);
	if (pow > 0)
		prec = ft_ignore_zero((int)nb, prec, pow);
	if (strchr(flags, '#'))
		prec = atoi(strchr(flags, '.') + 1) ? atoi(strchr(flags, '.') + 1) + 1 : 7;
	else
		prec += prec == 1 ? 0 : 1;
	prec += pow < 100 ? 4 : 5;
	prec += sign == -1 || strchr(flags, ' ') || strchr(flags, '+') ? 1 : 0;
	while (*flags && *flags != '.')
		ret = ret < atoi(flags++) ? atoi(flags - 1) : ret;
	ret = prec < ret ? ret + 1 : prec + 1;
	return (ret);
}

int		ft_size_g_f(char *flags, double nb, int pow, int sign)
{
	int		ret;
	int		prec;
	char	*t_flags;

	ret = 0;
	prec = nb > 9.0 ? 1 : 0;
	while ((nb /= 10.0) > 9.0)
		prec++;
	if (strchr(flags, '.') && pow > 0)
		prec = prec < atoi(strchr(flags, '.') +1) ? (double)atoi(strchr(flags, '.') +1) + 1.0 : prec + 1;
	t_flags = flags;
	while (*flags && *flags != '.')
		ret = ret < atoi(flags++) ? atoi(flags - 1) : ret;
	if (strchr(t_flags, '#'))
	{
		if (pow >= 0)
			if (prec < 7)
				prec = 7;
		if (pow < 0 && strchr(flags, '.'))
			prec = atoi(strchr(flags, '.') + 1) ? - pow + atoi(strchr(flags, '.') + 1) : -pow + 7;
		printf("prec == %d\n", prec);
	}
	if (strchr(t_flags, ' ') || strchr(t_flags, '+') || sign == -1)
		prec++;
	ret = prec < ret ? ret + 1 : prec + 1;
	return (ret);
}

int		ft_format_size_g(double nb, char *flags)
{
	int		ret;
	int		pow;
	int		sign;

	sign = nb < 0.0 ? -1 : 1;
	nb *= sign;
	pow = ft_get_pow(nb);
	printf("pow == %d\n", pow);
	if (!strchr(flags, '.') || pow < 0)
	{
		if (pow >= 6 || pow <= -5)
			ret = ft_size_g_e(flags, nb, pow, sign);
		else
			ret = ft_size_g_f(flags, nb, pow, sign);
	}
	else
	{
		if (atoi(strchr(flags, '.') + 1) <= pow)
			ret = ft_size_g_e(flags, nb, pow, sign);
		else
			ret = ft_size_g_f(flags, nb, pow, sign);
	}
	return (ret);
}

int main()
{
	int i;
	double j = -0.0001011;
	i = ft_format_size_g(j, "#g");
	printf("%d\n", i);
	i = printf("%#g", j);
	printf("\n%d\n", i);
}


// probleme pour exp negatif sur g_f
// probleme # sur g_f
// g_e normalement good
//
