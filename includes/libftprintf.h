#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <libft.h>
# include <stdarg.h>

typedef union	s_type
{
	char			c;
	unsigned char		uc;
	short int		hi;
	int			i;
	long int		li;
	long long int		lli;
	unsigned int		ui;
	unsigned long int	uli;
	unsigned long long int	ulli;
	double			d;
	long double		ld;	
}		t_type;

typedef struct	s_flag_f 
{
	char	flag;
	char	*(*fct)(char *, char);
}		t_flag_f;

typedef struct	s_form_f
{
	char	format;
	char	*(*fct)(va_list, char *);
}		t_form_f;

typedef struct	s_check
{
	const char	*aff;
	char		*error;
}		t_check;

typedef struct	s_string
{
	t_type		type;
	char		*str;
	int		size;
}		t_string;

int	ft_printf(const char *s, ...);

char	*flag_cleanse(const char *s, va_list ap);
char	*ft_arg(const char *s, char *format);
char	*ft_flag_indicator(char *s, char *flag);
char	*ft_flag_len(va_list ap, char *s, char *flag);

t_string	ft_format_c(va_list ap, char *flags);
t_string	ft_format_s(va_list ap, char *flags);
t_string	ft_format_p(va_list ap, char *flags);
t_string	ft_format_d(va_list ap, char *flags);
t_string	ft_format_i(va_list ap, char *flags);
t_string	ft_format_u(va_list ap, char *flags);
t_string	ft_format_o(va_list ap, char *flags);
t_string	ft_format_x(va_list ap, char *flags);
t_string	ft_format_bigx(va_list ap, char *flags);
t_string	ft_format_percent(va_list ap, char *flags);
/*
t_string	ft_format_n(va_list ap, char *flags);
t_string	ft_format_f(va_list ap, char *flags);
t_string	ft_format_g(va_list ap, char *flags);
t_string	ft_format_e(va_list ap, char *flags);
 */

/*
char	*ft_flag_min(t_form s);
char	*ft_flag_pt(t_form s);
char	*ft_flag_star(t_form s);
char	*ft_flag_l(t_form s);
char	*ft_flag_h(t_form s);
char	*ft_flag_hash(t_form s);
char	*ft_flag_spc(t_form s);
char	*ft_flag_plus(t_form s);
char	*ft_flag_zero(t_form s);
*/

#endif
