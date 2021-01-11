#include <libftprintf.h>
#include <stdio.h>
/*
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

   i = 0;
   check = 1;
   while (ft_strchr((const char *)flag, s[i]))
   check = s[i++] == '#' ? ft_parse_chr(s[ft_strlen(s) - 1], "xXo") : check;
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
   */

char	*ft_error_gestion(char *new_s, char *flag_clean, char *error)
{
	if (new_s)
		free(new_s);
	if (flag_clean)
		free(flag_clean);
	return (error);
}

int	ft_parse(char *s, char *flag, char *format)
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
char	*ft_flag_order(char *s)
{
	char		*ret;
	char		*tmp;
	char		*ref = "#0 +-";

	if (!(ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	tmp = ret;
	while (*ref)
	{
		if (ft_strchr(s, *ref))
		{
			*ret = *ref;
			ret++;
			ref++;
		}
		else
			ref++;
	}
	*ret = 0;
	printf("ret ==%s\n", tmp);
	free(s);
	return (tmp);
}

char	*flag_cleanse(char const *s, va_list ap)
{
	char		*flag = "- 0+#";
	char		*format = "cspdiuoxXnfge%";
	char		*flag_clean;
	char		*new_s;
	char		*tmp;

	flag_clean = NULL;
	if (!(new_s = ft_arg(s, format)))
		return (ft_error_gestion(NULL, NULL, "error_1"));
	if (!(ft_parse(new_s, flag, format)))
		return (ft_error_gestion(new_s, NULL, "error_2"));
	if (!(flag_clean = ft_flag_indicator(new_s, flag)))
		return (ft_error_gestion(new_s, NULL, "error_1"));
	if (!(flag_clean = ft_flag_order(flag_clean)))
		return (ft_error_gestion(new_s, NULL, "error_1"));
	tmp = flag_clean;
	if (!(flag_clean = ft_strjoin(tmp, ft_flag_len(ap, new_s, flag))))
		return (ft_error_gestion(new_s, tmp, "error_1"));
	free(tmp);
	flag_clean[ft_strlen(flag_clean)] = 0;
	printf("oui = %s\n", flag_clean);
	return (flag_clean);
}
