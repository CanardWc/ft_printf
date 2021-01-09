#include <libftprintf.h>
char		*ft_add_one_c(char *dst, char c)
{
	char	*ret;
	int		i;

	i = -1;
	if (!(ret = malloc(sizeof(char) * (ft_strlen(dst) + 2))))
		return (0);
	if (dst)
		while (dst[++i])
			ret[i] = dst[i];
	else
		i = 0;
	free(dst);
	ret[i++] = c;
	ret[i] = 0;
	return (ret);
}

char		*ft_asterisk(va_list ap, char *ret)
{
	char	*tmp;
	int		asterisk;

	tmp = ret;
	asterisk = va_arg(ap, int);
	ret = ft_strjoin(ret, ft_itoa(asterisk));
	free(tmp);
	return (ret);
}

char		*ft_arg(const char *s, char *format)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	j = -1;
	while (!ft_strchr(format, s[i]) && s[i])
		i++;
	if (!s[i])
		return (NULL);
	if (!(new_s = malloc(sizeof(char *) * i + 1)))
		return (0);
	while (++j <= i)
		new_s[j] = s[j];
	new_s[j] = 0;
	return (new_s);
}
/*
char		*ft_arg(const char *s, char *format)
{
	char	*new_s;
	char	*ret;
	char	*f;

	f = s;
	while (!ft_strchr(format, *f) && *f)\
		f++;
	if (!*f || !(new_s = (char *)malloc(sizeof(char) * ((f - s) + 1))))
		return (0);
	ret = new_s;
	while (s <= f)
		*new_s++ = *s++;
	*new_s = 0;
	return (ret);
}*/

char		*ft_flag_indicator(char *s, char *flag)
{
	char	*check;
	char	*indic;

	indic = NULL;
	check = ft_strchr(s, '-');
	while (ft_strchr(flag, *s))
	{
		if ((!(*s == '0' && check) && (!indic || !ft_strchr(indic, *s))))
			indic = ft_add_one_c(indic, *(s - 1));
		s++;
	}
	if (!indic)
		if (!(indic = (char *)malloc(1)))
			return (NULL);
	return (indic);
}

char		*ft_flag_len(va_list ap, char *s, char *flag)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (ft_strchr(flag, s[i]))
		i++;
	while (s[i])
	{
		if (s[i] == '*')
		{
			ret = ft_asterisk(ap, ret);
			i++;
		}
		ret = ft_add_one_c(ret, s[i]);
		i++;
	}
	if (!ret)
		if (!(ret= (char *)malloc(1)))
			return (0);
	return (ret);
}
