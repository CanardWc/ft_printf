#include <libftprintf.h>

char	*ft_flag_hash(t_form s)
{
	char		*ret;
	char		*tmp;

	ret = NULL;
	if (s[ft_strlen(s - 1)] == 'X')
		if (!(ret = ft_strjoin(ret, "0X")))
			return (0);
	else
		if (!(ret = ft_strjoin(ret, "0x")))
			return (0);
	tmp = ret;
	if (!(ret = ft_strjoin(ret, s)))
		return (0);
	free(tmp);
	return (ret);
}
