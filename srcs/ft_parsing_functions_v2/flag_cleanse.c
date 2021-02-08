/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_cleanse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:35:12 by edassess          #+#    #+#             */
/*   Updated: 2021/02/08 14:21:44 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

char		*ft_flag_indicator(char *s, char *flag, char *flag_clean \
		, int *nb);

int			ft_check_asterisk(char *s, char *format);

void		ft_flag_indicator2(char *s, char *flag_clean, int *asterisk\
		, char *format);

char		*ft_error_gestion(char *new_s, char *flag_clean, char *error)
{
	if (new_s)
		free(new_s);
	if (flag_clean)
		free(flag_clean);
	return (error);
}

int			ft_parse(char *s, char *flag, char *format)
{
	while (ft_strchr(flag, *s))
		if (*s++ == '#' && !ft_strchr("xXo", s[ft_strlen(s) - 1]))
			return (0);
	if (*s == '*')
		s++;
	else
		while (ft_isdigit(*s))
			s++;
	if (*s == '.')
	{
		s++;
		if (*s == '*')
			s++;
		else
			while (ft_isdigit(*s))
				s++;
	}
	if (*s == 'l')
		s += *(s + 1) == 'l' ? 2 : 1;
	else if (*s == 'h')
		s += *(s + 1) == 'h' ? 2 : 1;
	return ((int)ft_strchr(format, *s));
}

int			ft_alloc_flag_clean(char *s, char *format)
{
	int		i;
	int		check;
	int		check2;
	char	*tmp;

	i = 1;
	tmp = s;
	while (!ft_strchr(format, *tmp))
	{
		check = *tmp == '-' || check == 1 ? 1 : 0;
		check2 = *tmp++ == '+' || check2 == 1 ? 1 : 0;
	}
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

char		*flag_cleanse(char *s, va_list ap)
{
	char	*flag;
	char	*flag_clean;
	int		n[4];
	char	*format;

	format = "cpdiusxXonfge%";
	flag = "-0+# ";
	n[3] = 0;
	if (!(ft_parse(s, flag, format)))
		return (ft_error_gestion(NULL, NULL, "error_2"));
	n[0] = ft_check_asterisk(s, format) ? va_arg(ap, int) : 0;
	n[1] = ft_check_asterisk(s, format) == 2 ? va_arg(ap, int) : 0;
	n[1] = n[1] < 1 ? 0 : n[1];
	n[2] = n[0] < 0 && *(ft_strchr(s, '*') - 1) != '.' ? n[0] * -10 : 0;
	while (n[2] > 0 && n[3]++ != -1)
		n[2] /= 10;
	n[2] = n[1];
	while (n[2] > 0 && n[3]++ != -1)
		n[2] /= 10;
	n[3] += ft_alloc_flag_clean(s, format);
	if (!(flag_clean = ft_calloc(n[3] + 1, sizeof(char))))
		return (NULL);
	flag_clean = ft_flag_indicator(s, flag, flag_clean, n);
	ft_flag_indicator2(s, flag_clean, n, format);
	return (flag_clean);
}
