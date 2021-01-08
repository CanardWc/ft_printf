#include <libftprintf.h>
#include <stdio.h>

int	ft_format_treatment(const char *s, int i, va_list ap, t_list **ret)
{
	t_f_fcts	form_func[] = {
		{ 'c', &ft_format_c }, { 's', &ft_format_s },
		{ 'p', &ft_format_p }, { 'd', &ft_format_d },
		{ 'i', &ft_format_i }, { 'u', &ft_format_u },
		{ 'o', &ft_format_o }, { 'x', &ft_format_x },
		{ 'X', &ft_format_bigx }, { '%', &ft_format_percent }/*,
		{ 'n', &ft_format_n }, { 'f', &ft_format_f },
		{ 'g', &ft_format_g }, { 'e', &ft_format_e }*/ };

/*	t_f_fcts	flag_func[] = { { '-', ft_flag_min },
		{ '.', ft_flag_pt }, { '*', ft_flag_star },
		{ 'l', ft_flag_l }, { 'h', ft_flag_h },
		{ '#', ft_flag_hash }, { ' ', ft_flag_spc },
		{ '+', ft_flag_plus  }, { '0', ft_flag_zero }, }
	*/
	char		*form = "cspdiuoxX%";// <- need to add nfge
	char		*flag = "-.*lh# +0";
	//t_form	format;
	int		j;

	j = 0;

	/*
	s_flag = ft_flag_checking(s + i, ap);
	if (!ft_strcmp(s_flag, "error"))
	{
		
		return (NULL);
	}
	*/

	while (ft_strchr(flag, s[i + (++j)]))
	{
		//if (s[i + j] == '-')
		//	right to left;
		//if (s[i + j] == '#')
		//if (s[i + j] == ' ')
		//	blank before positive;
		//if (s[i + j] == '+')
		//if (s[i + j] == '0')
		//if (s[i + j] == 'l')
		//if (s[i + j] == 'h')
		//if (s[i + j] == '.')
		//if (s[i + j] == '*')
	}
	int	k = 0;
	while (form_func[k].form != *ft_strchr(form, s[i + j]))
		k++;
     	ft_lstadd_back(ret, ft_lstnew(form_func[k].fct(ap)));
	/*
	format.str = ret->content;
	format.type = form_func[k].form < form / 2 ? 0 : 1;
	k = 0;
	while (flag_func[k].form != *ft_strchr(*s_flag++, flag))
		k++;
	ret->content = flag_func[k];
	*/

	
	j++;
	return (j);
}

int	ft_display(const char *aff, t_list *ret, int i)
{
	char		*form = "cspdiuxX%nfge";
	char		*flag = "-.*lh# +0123456789";

	while (*aff)
	{
		if (*aff == '%')
		{
			while (ft_strchr(flag, *(++aff)))
				;
			while (ft_strchr(form, *aff))
				aff++;
			ft_putstr_fd(ret->content, 1);
			i += ft_strlen(ret->content);
			ret = ret->next;
		}
		ft_putchar_fd(*aff, 1);
		aff++;
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	t_list		*ret;
	const char	*aff;
	int		i;

	ret = NULL;
	va_start(ap, s);
	i = -1;
	aff = s;
	while (s[++i])
		if (s[i] == '%')
			s += ft_format_treatment(s, i, ap, &ret);
	va_end(ap);
	return (ft_display(aff, ret, i));
}

int	main(void)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 4);
	ft_printf("hey %s \n la bess ? \n %.*d \n %c\n %  p\n", "boloss", 123446, 'u', s);
	return (0);
}
