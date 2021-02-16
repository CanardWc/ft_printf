#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libraries/libft/includes/libft.h"
# include <stdarg.h>

typedef struct		s_string
{
	char		*str;
	int		size;
}			t_string;

typedef struct	s_flag_f 
{
	char		flag;
	char		*(*fct)(char *, char *, char);
}			t_flag_f;

typedef struct		s_form_f
{
	char		format;
	char		*(*fct)(va_list, char *, int);
}			t_form_f;

typedef struct		s_check
{
	const char	*aff;
	char		*error;
}			t_check;

int			ft_printf(const char *s, ...);

char			*flag_cleanse(char *s, va_list ap);
char			*ft_arg(const char *s, char *format);
char			*ft_flag_indicator(char *s, char *flag, char *flag_clean, int *nb);
char			*ft_flag_len(va_list ap, char *s, char *flag);

char			*ft_format_c(va_list ap, char *flags, int i);
char			*ft_format_s(va_list ap, char *flags, int i);
char			*ft_format_p(va_list ap, char *flags, int i);
char			*ft_format_d(va_list ap, char *flags, int i);
char			*ft_format_i(va_list ap, char *flags, int i);
char			*ft_format_u(va_list ap, char *flags, int i);
char			*ft_format_o(va_list ap, char *flags, int i);
char			*ft_format_x(va_list ap, char *flags, int i);
char			*ft_format_bigx(va_list ap, char *flags, int i);
char			*ft_format_percent(va_list ap, char *flags, int i);
char			*ft_format_f(va_list ap, char *flags, int i);
char			*ft_format_n(va_list ap, char *flags, int i);
char			*ft_format_e(va_list ap, char *flags, int i);
/*
char			*ft_format_g(va_list ap, char *flags, int i);
 */

char			*ft_flag_number(char *flag, char *str, char format);
char			*ft_flag_min(char *flag, char *str, char format);
char			*ft_flag_hash(char *flag, char *str, char format);
char			*ft_flag_spc(char *flag, char *str, char format);
char			*ft_flag_plus(char *flag, char *str, char format);
char			*ft_flag_zero(char *flag, char *str, char format);
char			*ft_flag_number(char* flag, char* str, char format);

#endif
