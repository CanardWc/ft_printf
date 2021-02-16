/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edassess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:24:27 by edassess          #+#    #+#             */
/*   Updated: 2021/02/12 12:24:04 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdio.h>

const	t_flag_f	flag_fct[] = { { '1', ft_flag_number }, 
		{ '-', ft_flag_min }, { ' ', ft_flag_spc }, 
		{ '+', ft_flag_plus }, { '0', ft_flag_zero }, 
		{'#', ft_flag_hash }, };

const	t_form_f	form_fct[] = {
		{ 'c', &ft_format_c }, { 's', &ft_format_s },
		{ 'p', &ft_format_p }, { 'd', &ft_format_d },
		{ 'i', &ft_format_i }, { 'u', &ft_format_u },
		{ 'o', &ft_format_o }, { 'x', &ft_format_x },
		{ 'X', &ft_format_bigx }, { 'n', &ft_format_n }, 
		{ 'f', &ft_format_f }, { 'e', &ft_format_e }, 
		{ '%', &ft_format_percent } };

char		*ft_flag_treatment(char *s_flag, char *format, char type)
{
	char		*flag_list = "- +0#";
	char		*stock;

	if (ft_strchr("123456789", *s_flag))
		return (format = flag_fct[0].fct(s_flag, format, type));
	while ((stock = ft_strchr(flag_list, *s_flag)))
		format = flag_fct[stock - flag_list].fct(\
				s_flag++, format, type);
	return (format);
}

const char	*ft_format_treatment(const char *s, int i, va_list ap, t_list **ret, \
		t_check *err_chk)
{
	char		*format_list = "cspdiuoxXnfge%";
	char		*s_flag;
	char		*str;
	int		j;
	int		k;

	j = 1;
	k = 0;
	s_flag = flag_cleanse((char *)s + i + 1, ap);
	if (!ft_strncmp(s_flag, "error", 5))
		return ((err_chk->error = s_flag));
	while (ft_strchr("-.*lh# +0123456789", s[i + j]))
		j++;
	while (form_fct[k].format != *ft_strchr(format_list, s[i + j]))
		k++;
	str = form_fct[k].fct(ap, s_flag, i);
	str = ft_flag_treatment(s_flag, str, form_fct[k].format);
	ft_lstadd_back(ret, ft_lstnew(str));
	free(s_flag);
//	printf("%c\n", *(s + j));
	return (s + j);
}

int			ft_display(t_check err_chk, t_list *ret, int i)
{
	//	char		*form = "cspdiuoxXnfge%";
	char		*flag = "-.*lh# +0123456789";
	t_list		*tmp;
	int			j;

	j = 0;
	(void)i;
	tmp = ret;
	while (*(err_chk.aff) && !err_chk.error)
	{
		if (*err_chk.aff == '%')
		{
			while (ft_strchr(flag, *(++err_chk.aff)))
				;
			err_chk.aff++;
			ft_putstr_fd((char *)ret->content, 1);
			j += ft_strlen((char *)ret->content);
			ret = ret->next;
		}
		if (*err_chk.aff)
		{
			ft_putchar_fd(*err_chk.aff, 1);
			err_chk.aff++;
			j++;
		}
	}
	ft_lstclear(&tmp, &free);
	//if (err_chk.error)
	//	return (ft_error_gestion());
	return (j);
}

int			ft_printf(const char *s, ...)
{
	va_list		ap;
	t_list		*ret;
	t_check		err_chk;
	int		i;

	ret = NULL;
	va_start(ap, s);
	i = -1;
	err_chk.aff = s;
	err_chk.error = NULL;
	while (s[++i])
	{
		if (s[i] == '%')
			if (!(s = ft_format_treatment(s, i, ap, &ret, &err_chk)) \
					&& err_chk.error)
				break;
	}
	va_end(ap);
	return (ft_display(err_chk, ret, i));
}
/*
   int			main(void)
   {
   char	*s;

   s = (char *)malloc(sizeof(char) * 4);
   ft_printf("X = %X\nc = %c\nd = %d\ni = %i\no = %o\np = %p\npercent = %%\ns = %s\nu = %u\nx = %x\n", \
   42,         'z',    -333,   -10,    123,     s,              "vaginette", 1234,   42);
   ft_printf("X = %X\nc = %c\nd = %d\ni = %i\no = %o\np = %p\npercent = %%\ns = %s\nu = %u\nx = %x\nf = %f\ne = %e\nvi hende", \
   42, 'z', -333, -10, 123, s, "vaginette", 1234, 42, 123.123, 0.00000005);
   return (0);
   }*/
