/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_cleanse_ft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:40:48 by edassess          #+#    #+#             */
/*   Updated: 2021/02/08 16:54:07 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <libft.h>
#include <unistd.h>
#include <stdio.h>

void		ft_flag_order(char *s)
{
	char	c;
	char	*tmp;
	char	*ref;

	ref = "0-# +";
	while (ft_strchr(ref, *s) && *s)
	{
		while (!ft_strchr(s, *ref))
			ref++;
		c = *s;
		tmp = ft_strchr(s, *ref);
		*s = *ref++;
		*tmp = c;
		s++;
	}
}

int			ft_check_asterisk(char *s, char *format)
{
	int		i;

	i = 0;
	while (!ft_strchr(format, *s))
	{
		if (*s == '*')
			i++;
		s++;
	}
	return (i);
}

char		*ft_asterisk(int nb, char *flag_clean)
{
	int		i;
	int		tmp;

	i = 1;
	if (nb < 0)
		nb *= -1;
	tmp = nb;
	while ((tmp /= 10) > 0)
		i++;
	while (*flag_clean)
		flag_clean++;
	while (i > 0)
	{
		flag_clean[--i] = nb % 10 + '0';
		nb /= 10;
	}
	return (flag_clean);
}

void		ft_flag_indicator2(char *s, char *flag_clean, int *asterisk\
		, char *format)
{
	int		i;

	i = 0;
	while (*flag_clean)
		flag_clean++;
	while (ft_strchr("-0 +#", *s))
		s++;
	while (!ft_strchr(format, *s))
	{
		if (*s == '*')
		{
			flag_clean = ft_asterisk(asterisk[i], flag_clean);
			s++;
			while (*flag_clean)
				flag_clean++;
			i++;
		}
		else
			*flag_clean++ = *s++;
	}
	*flag_clean++ = *s;
	*flag_clean = '\0';
}

char		*ft_flag_indicator(char *s, char *flag, char *flag_clean, int *nb)
{
	int		check;
	int		check2;
	int		check3;
	char	*tmp;

	check = 0;
	check2 = 0;
	check3 = 0;
	tmp = s;
	while (!ft_strchr("cpdiusxXonfge%", *tmp))
	{
		check = *tmp == '-' ? 1 : check;
		check2 = *tmp++ == '+' ? 1 : check2;
	}
	if (*tmp == 'c' || *tmp == 's' || *tmp == '#')
		check3 = 1;
	tmp = flag_clean;
	if (nb[0] < 0 && *(ft_strchr(s, '*') - 1) != '.')
	{
		*flag_clean++ = '-';
		nb[0] *= -1;
		check = 1;
	}
	while (ft_strchr(flag, *s))
	{
		if ((!(*s == '0' && check) && (!ft_strchr(tmp, *s))) && \
				(!(*s == ' ' && check2) && (!*tmp || !ft_strchr(tmp, *s))) &&\
				(!((*s == ' ' || *s == '+') && check3)))
			*flag_clean++ = *s;
		s++;
	}
	ft_flag_order(tmp);
	return (tmp);
}
