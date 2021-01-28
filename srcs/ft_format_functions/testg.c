/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:46:41 by edassess          #+#    #+#             */
/*   Updated: 2021/01/28 17:23:11 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
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
	while (((int)nb % 10) == 0)
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
	if (((int)nb % 10) >= 5)
	{
		nb /= 10.0;
		while ((int)nb % 10 == 9)
		{
			prec--;
			nb /= 10.0;
		}
		printf("prec == %d\n", prec);
		return (prec);
	}
	nb /= 10.0;
	prec--;
	while ((int)nb % 10 == 0)
	{
		prec--;
		nb /= 10.0;
	}
	printf("prec == %d\n", prec);
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

int		ft_exp(int n, int exp)
{
	int		ret;

	ret = 1;
	while (exp--)
		ret *= 10;
	return (ret);
}
double	ft_exp_double(int n, int exp)
{
	int		ret;

	ret = 1;
	while (exp--)
		ret *= n;
	return (ret);
}

int		ft_i(double nb, int pow, int prec, int i)
{
	int		ret;

	printf("exp == %d\n", (ft_exp(10, pow) * 9));
	printf("como\n");
	if (pow >= 0 && (int)nb >= (ft_exp(10, pow) * 9) && i < (pow - prec))
	{
	i++;
		printf(" prec == %d\n", prec);
		nb /= 10.0;
		printf("quoi ==%f\n", nb);
		printf(" i == %d\n", i);
		i = ft_i(nb, pow - 1, prec, i);
	}
	if ((int)nb >= (ft_exp(10, i) * 9))
	{
		printf("oui\n");
		return (prec);
	}
	return (i);
}

double	ft_round_up(double nb, int pow, int prec)
{
	int		i;

	i = 0;
	printf("%d\n", (ft_exp(10, pow) * 9));
/*	if ((int)nb >= (ft_exp(10, pow) * 9) && i > prec)
	{
		i++;
		ft_round_up((int)nb / 10, pow - 1, prec, i);
	}
	else if (i == prec)
		nb = ft_exp_double(10, pow + 1);*/
	if (ft_i(nb, pow, prec, i) == prec)
	{
		printf("asdfg\n");
			nb = ft_exp_double(10, pow + 1);
	}
	printf("%f\n", nb);
	return (nb);
}
/*
double	ft_round_up(double nb, int pow, int prec)
{
	int		i;

	i = -1;
	if (pow >= 0)
		while (++i <= prec)
			if ((int)(nb / ft_exp(10, prec)) % ft_exp(10, pow - (i + 1)) != 9)
				break;
	printf("i == %d\n", i);
	printf("prec == %d\n", prec);
	printf("pow == %d\n", pow);
	if (i == prec + 1)
		if ((int)nb % ft_exp(10, pow - prec - 1) == 9)
			nb = ft_exp_double(10, pow + 1);
	printf("oui ==%f\n", nb);
	return (nb);
}
*/
int		ft_format_size_g(double nb, char *flags)
{
	int		ret;
	int		pow;
	int		sign;
	int		prec;

	prec = strchr(flags, '.') ? atoi(strchr(flags, '.') + 1) : 6;
	pow = ft_get_pow(nb);
	nb = ft_round_up(nb, pow, prec);
	sign = nb < 0.0 ? -1 : 1;
	nb *= sign;
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
	double k = 99990000.00;
//		while (1)
//		{
/*		i = ft_format_size_g(j, " .g");
		printf("%d\n", i);
		i = printf("% .2g", j);
		printf("\n%d\n", i);*/
	printf("====E====\n");
	i = ft_format_size_g(k, ".4g");
	printf("%d\n", i);
	i = printf("%.4g", k);
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
