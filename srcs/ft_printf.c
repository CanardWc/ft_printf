#include <libftprintf.h>
#include <stdio.h>

/*
char	*ft_flag_treatment(const char *s, char *format, char type)
{
	t_flag_f	flag_func[] = { { '-', ft_flag_min },
		{ '.', ft_flag_pt }, { '*', ft_flag_star },
		{ 'l', ft_flag_l }, { 'h', ft_flag_h },
		{ '#', ft_flag_hash }, { ' ', ft_flag_spc },
		{ '+', ft_flag_plus  }, { '0', ft_flag_zero }, };
	char		*flag_list = "-.*lh# +0";
	int		i;

	while (*s)
	{
		i = 0;
		while (flag_func[i].form != *ft_strchr(flag_list, *s))
			i++;
		format = flag_func[i].fct(format, type);
		s++;
	}
	return (format);
}
*/
const char	*ft_format_treatment(const char *s, int i, va_list ap, t_list **ret, \
		t_check *err_chk)
{
	t_form_f	form_func[] = {
		{ 'c', &ft_format_c }, { 's', &ft_format_s },
		{ 'p', &ft_format_p }, { 'd', &ft_format_d },
		{ 'i', &ft_format_i }, { 'u', &ft_format_u },
		{ 'o', &ft_format_o }, { 'x', &ft_format_x },
		{ 'X', &ft_format_bigx }, { 'n', &ft_format_n }, 
		{ 'f', &ft_format_f }, /*{ 'g', &ft_format_g }, 
		{ 'e', &ft_format_e }, */{ '%', &ft_format_percent } };
	char		*format_list = "cspdiuoxXnfge%";// <- need to add nfge
	char		*s_flag;
	int		j;
	int		k;

	j = 1;
	k = 0;
	s_flag = flag_cleanse(s + i + 1, ap);
	if (!ft_strncmp(s_flag, "error", 5))
		return ((err_chk->error = s_flag));
	while (ft_strchr("-.*lh# +0123456789", s[i + j]))
		j++;
	while (form_func[k].format != *ft_strchr(format_list, s[i + j]))
		k++;
     	ft_lstadd_back(ret, ft_lstnew((void *)form_func[k].fct(ap, s_flag, i)));
	printf("hey\n");
	//ret->content = ft_flag_treatment(s_flag, ret->content, form_func->format);
	//free(s_flag);
	return (s + j + 1);
}

int	ft_display(t_check err_chk, t_list *ret, int i)
{
	char		*form = "cspdiuoxXnfge%";
	char		*flag = "-.*lh# +0123456789";

	while (*(err_chk.aff) && !err_chk.error)
	{
		if (*err_chk.aff == '%')
		{
			while (ft_strchr(flag, *(++err_chk.aff)))
				;
			while (ft_strchr(form, *err_chk.aff))
				err_chk.aff++;
			ft_putstr_fd((char *)ret->content, 1);
			i += ft_strlen((char *)ret->content);
			ret = ret->next;
		}
		ft_putchar_fd(*err_chk.aff, 1);
		err_chk.aff++;
	}
	ft_lstclear(&ret, &free);
	//if (err_chk.error)
	//	return (ft_error_gestion());
	return (i);
}

int	ft_printf(const char *s, ...)
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
		if (s[i] == '%')
			if (!(s = ft_format_treatment(s, i, ap, &ret, &err_chk)) \
					&& err_chk.error)
				break;
	printf("couc = %s\n", err_chk.error);
	va_end(ap);
	return (ft_display(err_chk, ret, i));
}

int	main(void)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 4);
	ft_printf("X = %X\nc = %c\nd = %d\ni = %i\no = %o\np = \
			%p\npercent = %%\ns = %s\nu = %u\nx = %x\nvi hende", \
			42, 'z', 333, 1234, 123, 42, s, "vaginette", 1234, 42);
	return (0);
}
