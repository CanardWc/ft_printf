/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 04:31:06 by fgrea             #+#    #+#             */
/*   Updated: 2018/03/18 20:14:24 by fgrea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "../libft/includes/libft.h"

# define BUFFER_SIZE 4096

# define MAJ_HEXA "0123456789ABCDEF"
# define MIN_HEXA "0123456789abcdef"
# define OCTAL "01234567"
# define BINARY "01"
# define CONVERSION "sSpdDioOuUxXcCb"
# define NON_VALID "%BHIJKMNPQRTVWYZ{}"

# define DIESE 0
# define ZERO 1
# define MORE 2
# define LESS 3
# define SPACE 4

# define HH 0
# define H 1
# define LL 2
# define L 3
# define J 4
# define Z 5

typedef struct	s_precision
{
	int			actif;
	int			len;
}				t_precision;

typedef struct	s_env
{
	char		buff[BUFFER_SIZE];
	int			index;
	const char	*str;
	size_t		cur;
	char		flag[5];
	int			size;
	int			dot;
	int			precision;
	char		modif[6];
	char		conv;
	size_t		printcar;
	int			len;
	int			ret;
	void		*argum;
}				t_env;

int				ft_printf(const char *format, ...);
int				ft_reader(t_env *arg, va_list ap);
int				ft_parse(t_env *arg);
void			ft_parse_flag(t_env *arg);
void			ft_parse_size(t_env *arg);
void			ft_parse_precision(t_env *arg);
void			ft_parse_modif(t_env *arg);
void			ft_parse_conv(t_env *arg);

int				ft_add_arg(t_env *arg, va_list ap);

int				ft_add_sgn(t_env *arg, ssize_t nbr);
int				ft_add_sgn_pos(t_env *arg, ssize_t nbr);
int				ft_add_sgn_neg(t_env *arg, ssize_t nbr);

int				ft_add_b(t_env *arg, size_t nbr);
int				ft_add_p(t_env *arg, va_list ap);
int				ft_add_octal(t_env *arg, size_t nbr);
int				ft_add_uns(t_env *arg, size_t nbr);
int				ft_add_hexa(t_env *arg, size_t nbr);

int				ft_add_c(t_env *arg, va_list ap);
int				ft_add_wc(t_env *arg, va_list ap);
int				ft_add_s(t_env *arg, va_list ap);
int				ft_add_ws(t_env *arg, va_list ap);
int				ft_add_double_percent(t_env *arg);
int				ft_add_non_valid(t_env *arg);

int				ft_add_flag_diese(t_env *arg);
int				ft_add_flag_more(t_env *arg);
int				ft_add_flag_space(t_env *arg);

int				ft_add_flag_zero(t_env *arg, int start, int end);
int				ft_add_flag_spaces(t_env *arg, int start, int end);

void			ft_printf_putnbr_uns(t_env *arg, size_t nbr);
void			ft_printf_putchar(t_env *arg, unsigned char c);
void			ft_printf_putstr(t_env *arg, char const *s);
void			ft_printf_putwstr(t_env *arg, wchar_t const *s);
void			ft_printf_putwstr_n(wchar_t const *s, int n);

int				ft_printf_nbrlen_uns(t_env *arg, size_t nbr);
int				ft_printf_strlen(const char *s);
int				ft_printf_strwlen(const wchar_t *s);

int				ft_add_size(t_env *arg, int nbr);

int				ft_caste_sgn(t_env *arg, va_list ap);
int				ft_caste_uns(t_env *arg, va_list ap);

void			ft_buff_gestion(t_env *arg);
void			ft_add_to_buff(t_env *arg, char *s);
void			ft_add_c_to_buff(t_env *arg, char c);
void			ft_buff_final(t_env *arg);

void			ft_add_str_n(t_env *arg, const char *s, int n);
void			ft_add_wstr(t_env *arg, wchar_t const *str);
void			ft_add_wstr_n(t_env *arg, wchar_t *s, int n);
void			ft_add_wchar(t_env *arg, wchar_t c);

void			ft_add_nbr_lng(t_env *arg, long long int n);
void			ft_add_nbr_hexa(t_env *arg, size_t nb);
void			ft_add_nbr_base(t_env *arg, unsigned long long int n, \
				char *base);
void			ft_add_nbr(t_env *arg, int n);
void			ft_add_nbr_uns(t_env *arg, unsigned long long int n);

#endif
