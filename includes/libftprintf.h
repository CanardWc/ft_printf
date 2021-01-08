#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <libft.h>
# include <stdarg.h>

typedef struct	s_f_fcts
{
	char	form;
	char	*(*fct)(va_list);
}		t_f_fcts;

typedef struct	s_form
{
	unsigned char	*ret;
	int		type;
}		t_form;

int	ft_printf(const char *s, ...);

char	*ft_format_c(va_list ap);
char	*ft_format_s(va_list ap);
char	*ft_format_p(va_list ap);
char	*ft_format_d(va_list ap);
char	*ft_format_i(va_list ap);
char	*ft_format_u(va_list ap);
char	*ft_format_o(va_list ap);
char	*ft_format_x(va_list ap);
char	*ft_format_bigx(va_list ap);
char	*ft_format_percent(va_list ap);
/*
char	*ft_format_n(va_list ap);
char	*ft_format_f(va_list ap);
char	*ft_format_g(va_list ap);
char	*ft_format_e(va_list ap);
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
