
//#include "ft_printf.h"

#include <stdlib.h>

char	*ft_add_one_c(char *dst, char c);
char	*ft_asterisk(va_list ap, char *ret);
char	*ft_arg(const char *s, char *format);
char	*ft_flag_indicator(char *s, char *flag);
char	*ft_flag_len(va_list ap, char *s, char *flag);

int			ft_parse_chr(char c, char *format)
{
	int		i;

	i = 0;
	while(format[i])
	{
		if (format[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int			ft_parse(char *s, char *flag, char *format)
{
	int		i;
	int		check;

	i = -1;
	check = 0;
	while (ft_strchr(flag, s[++i]))
		check = s[i] == '#' ? ft_parse_chr(s[ft_strlen(s) - 1], "xXo") : 1;
	if (s[i] == '*')
		i++;
	else
		while (ft_isdigit(s[i]))
			i++;
	i = s[i] == '.' ? i + 1 : i;
	if (s[i] == '*')
		i++;
	else
		while (ft_isdigit(s[i]))
			i++;
	if (s[i] == 'l')
		i += s[i + 1] == 'l' ? 2 : 1;
	else if (s[i] == 'h')
		i += s[i + 1] == 'h' ? 2 : 1;
	return (check && ft_strchr(format, s[i]) ? 1 : 0); 
}

char		*flag_cleanse(va_list ap, char const *s, char *flag, char *format)
{
	char		*flag_clean;
	char		*new_s;
	char		*tmp;
	int			error;

	error = (new_s = ft_arg(s, format)) ? 0 : 1;
	error = (ft_parse(new_s, flag, format)) && !error ? 0 : 1;
	flag_clean = ft_flag_indicator(new_s, flag);
	tmp = flag_clean;
	error = (flag_clean = ft_strjoin(flag_clean, ft_flag_len(ap, new_s, flag)))\
			&& !error ? 0 : 1;
	free(tmp);
	return (error ? "error" : flag_clean);
}
