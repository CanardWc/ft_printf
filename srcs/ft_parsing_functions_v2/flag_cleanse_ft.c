/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_cleanse_ft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:40:48 by edassess          #+#    #+#             */
/*   Updated: 2021/01/14 17:42:51 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

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

	i = 0;
	tmp = nb;
	while ((tmp /= 10) > 9)
		i++;
	while (i >= 0)
	{
		flag_clean[i--] = nb % 10 + '0';
		nb /= 10;
	}
	return (flag_clean);
}

void		ft_flag_indicator2(char *s, char *flag_clean, int *asterisk)
{
	int		i;
	char	*format;

	format = "cspdiuxXnfgeo%";
	i = 0;
	while (!ft_strchr(format, *s))
	{
		if (*s == '*')
		{
			flag_clean = ft_asterisk(asterisk[i], flag_clean);
			s++;
			i++;
		}
		*flag_clean++ = *s++;
	}
	*flag_clean = *s;
}

char		*ft_flag_indicator(char *s, char *flag, char *flag_clean, int *nb)
{
	char	*check;
	char	*check2;
	char	*tmp;
	int		i;

	i = 0;
	check = ft_strchr(s, '-');
	check2 = ft_strchr(s, '+');
	tmp = flag_clean;
	while (ft_strchr(flag, *s))
	{
		if (((!(*s == '0' && check)) && (!*tmp || !ft_strchr(tmp, *s))) || \
				(!(*s == ' ' && check2) && (!*tmp || !ft_strchr(tmp, *s))))
		{
			*flag_clean = *s;
			flag_clean++;
		}
		s++;
	}
	ft_flag_indicator2(s, flag, nb);
	return (tmp);
}

int			ft_alloc_flag_clean(char *s, char *flag, char *format)
{
	int		i;
	char	*check;
	char	*check2;
	char	*tmp;

	i = 2;
	check = ft_strchr(s, '-');
	check2 = ft_strchr(s, '+');
	tmp = s;
	while (!ft_strchr(format, *s))
	{
		if (*s == '*')
			s++;
		else
		{
			if ((!(*s == '0' && check && !ft_isdigit(s[-1]))) || \
					(!(*s == ' ' && check2)))
				i++;
			s++;
		}
	}
	return (i);
}
