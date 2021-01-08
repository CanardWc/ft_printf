
//#include "ft_printf.h"

#include <stdlib.h>

char		*ft_add_one_c(char *dst, char c)
{
	char	*tmp;

	tmp = dst;
	if (!(dst = malloc(sizeof(char *) * ft_strlen(dst) + 2)))
		return (0);
	dst = ft_strcpy(dst, tmp);
	free(tmp);
	dst[ft_strlen(dst) + 1] = c;
	dst[ft_strlen(dst) + 2] = 0;
	return (dst);
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
	char	*tmp;

	i = -1;
	while (ft_strchr(flag, s[++i]))
	{
		check = ft_strchr(s, '-') && s[i] == 0 ? 0 : 1;
		if (!ft_strchr(indic, s[i]) && check)
			indic = ft_add_one_c(indic, s[i]);
	}
	return (indic);
}

char		*ft_flag_len(va_list ap, char *s, char *flag)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
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
