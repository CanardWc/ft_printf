/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:46:41 by edassess          #+#    #+#             */
/*   Updated: 2021/02/01 16:10:02 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

long double	ft_dmod(long double a, long double b)
{
	long double	mod;

	mod = a < 0 ? a * -1 : a;
	b = b < 0 ? b * -1 : b;
	while (mod >= b)
		mod = mod - b;
	return (a < 0 ? mod * -1 : mod);
}

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
		while(fl >= 10.0)
		{
			fl /= 10.0;
			pow++;
		}
	return(pow);
}


int		ft_ignore_zero(double nb, int prec, int pow)
{
	int		i;

	i = 0;
	if (nb < 1.0 && (pow *= -1) != -1)
		while ((pow + 1 - prec) > i)
		{
			nb *= 10.0;
			i++;
		}
	else
		while ((pow + 1 - prec) > i)
		{
			nb /= 10.0;
			i++;
		}
	i = 0;
	while (ft_dmod(nb, 10.0) == 0)
	{
		i++;
		nb /= 10.0;
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
		prec = ft_ignore_zero(nb, prec, pow);
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

int		ft_neg_pow_f(double nb, int pow, int sign, int t_prec)
{
	int		prec;

	prec = 0;
	pow *= -1;
	while ((pow + t_prec) > prec)
	{
		nb *= 10.0;
		prec++;
	}
	if (ft_dmod(nb, 10.0) >= 5)
	{
		nb /= 10.0;
		while (ft_dmod(nb, 10.0) == 9)
		{
			prec--;
			nb /= 10.0;
		}
		return (prec);
	}
	nb /= 10.0;
	prec--;
	while (ft_dmod(nb, 10.0) == 0)
	{
		prec--;
		nb /= 10.0;
	}
	return (prec);
}

int		ft_size_g_f(char *flags, double nb, int pow, int sign)
{
	int		ret;
	int		prec;
	char	*t_flags;
	int		t_prec;

	ret = 0;
	prec = 0;
	t_flags = flags;
	if (strchr(flags, '.'))
		t_prec = atoi(strchr(flags, '.') + 1) == 0 ? 1 : atoi(strchr(flags, '.') + 1); 
	if (pow < 0)
	{
		if (strchr(flags, '#'))
			prec = t_prec + (pow * -1);
		else
		{
			prec = ft_neg_pow_f(nb, pow, sign, t_prec);
		}
		prec += 3;
	}
	/*	if (pow >= 0)
		{

		}*/
	prec += sign == -1 || strchr(flags, ' ') || strchr(flags, '+') ? 1 : 0;
	return (prec);
}

double		ft_exp(double n, int exp)
{
	double		ret;

	ret = n;
	if (exp)
		while (--exp)
			ret *= n;
	else
		return (1);
	return (ret);
}

int	ft_check_round_up_pos(double nb, int pow, int prec)
{
	int	i;

	i = 0;
	printf("dmod == %Lf\n", ft_dmod(nb, 1));
	while (pow-- >= 0 && nb >= ft_exp(10.0, pow + 1) * 9)
	{
		printf("wtf%d\n", pow);
		printf("exp == %f\n", ft_exp(10.0, pow + 1) * 9);
		i++;
		nb -= (ft_exp(10, pow + 1) * 9);
	}
	printf("i == %d\n", i);
	printf("nb == %f\n", nb);
	if (i > prec)
		return (1);
	return (0);
}

double	ft_round_up(double nb, int pow, int prec)
{
	int		i;

	i = 0;
	if (pow > 0)
	if (ft_check_round_up_pos(nb, pow, prec))
	{
			nb = ft_exp(10, pow + 1);
			printf("nb ==%f\n", nb);
	}
	else if (pow < 0)
	{
		while (pow++ < 0)
			nb *= 10.0;
		while (prec-- > 0)
			nb *= 10.0;
	}
	return (nb);
}

int		ft_format_size_g(double nb, char *flags)
{
	int		ret;
	int		pow;
	int		sign;
	int		prec;

	prec = strchr(flags, '.') ? atoi(strchr(flags, '.') + 1) : 6;
	pow = ft_get_pow(nb);
	nb = ft_round_up(nb, pow, prec);
	pow = ft_get_pow(nb);
	printf("pow == %d\n", pow);
	sign = nb < 0.0 ? -1 : 1;
	nb *= sign;
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

void delay(int number_of_seconds) 
{ 
	// Converting time into milli_seconds 
	int milli_seconds = 1000 * number_of_seconds; 

	// Storing start time 
	clock_t start_time = clock(); 

	// looping till required time is not achieved 
	while (clock() < start_time + milli_seconds) 
		; 
}

int main()
{
	int i;
	double j = 9990000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.00;
	double f = 0.000099;
	double k = 9999999.5555;
//		while (1)
//		{
/*		i = ft_format_size_g(j, " .g");
		printf("%d\n", i);
		i = printf("% .2g", j);
		printf("\n%d\n", i);*/
	printf("====E====\n");
	i = ft_format_size_g(k, ".7g");
	printf("%d\n", i);
	i = printf("%.7g", k);
	printf("\n%d\n", i);
/*		printf("====F====\n");
		i = ft_format_size_g(0.0000999, " .g");
		printf("%d\n", i);
		i = printf("% .3g", 0.0000999);
		printf("\n%d\n", i);*/
//		delay(2);
//		sleep(1000);
//		}
}
/*if 10 % 10 exposant pow - precision == 9, arrondir, que des 9?
  si oui nb = 10 exposant pow + 1
  besoin  de functions exposant
  voir comment faire pour exposant negatif
  */
// probleme pour exp negatif sur g_f
// probleme # sur g_f
// g_e normalement good
//
