#include <libftprintf.h>
#include <stdio.h>
#include <stdlib.h>

char		*ft_add_one_c(char *dst, char c)
{
	char	*ret;
	int		i;

	i = -1;
	if (!(ret = malloc(sizeof(char) * (dst ? (ft_strlen((const char *)dst) + \
							2) : 2))))
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

char		*ft_flag_indicator(char *s, char *flag)
{
	int		check;
	int		i;
	char	*indic;

	indic = NULL;
	i = -1;
	check = ft_parse_chr('-', s);
	while (ft_strchr(flag, s[++i]))
		if ((!(s[i] == '0' && check) && (!indic || !ft_strchr(indic, s[i]))))
			indic = ft_add_one_c(indic, s[i]);
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
	return (ret);
}
