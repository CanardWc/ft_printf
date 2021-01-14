/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_cleanse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:35:12 by edassess          #+#    #+#             */
/*   Updated: 2021/01/14 17:40:23 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>

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

void		ft_flag_order(char *s)
{
	char	c;
	char	*tmp;
	char	*ref;

	ref = "#0 +-";
	while (ft_strchr(ref, *s))
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

char		*flag_cleanse(char *s, va_list ap)
{
	char	*flag;
	char	*format;
	char	*flag_clean;
	int		asterisk[3];
	int		i;

	flag = "-0+#";
	format = "cspdiuoxXnfge%";
	i = 0;
	if (!(ft_parse(s, flag, format)))
		return (ft_error_gestion(NULL, NULL, "error_2"));
	asterisk[0] = ft_check_asterisk(s, format) ? va_arg(ap, int) : 0;
	asterisk[1] = ft_check_asterisk(s, format) == 2 ? va_arg(ap, int) : 0;
	asterisk[2] = asterisk[0];
	while ((asterisk[2] /= 10) > 0)
		i++;
	asterisk[2] = asterisk[1];
	while ((asterisk[2] /= 10) > 0)
		i++;
	i += ft_alloc_flag_clean(s, flag, format);
	if (!(flag_clean = ft_calloc(i, sizeof(char))))
		return (NULL);
	flag_clean = ft_flag_indicator(s, flag, flag_clean, asterisk);
	ft_flag_order(flag_clean);
	return (flag_clean);
}
