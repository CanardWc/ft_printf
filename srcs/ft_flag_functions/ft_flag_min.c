
#include "ft_printf.h"

int		ft_flag_minus()
{
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	len = ft_strlen(ret) > width ? ft_strlen(ret) : width;
	if (!(tmp = malloc(sizeof(char *) * len + 1)))
		return (0);
	while (str[++i])
		tmp[i] = str[i];
	while (i < len)
		tmp[i] = ' ';
	free(str);
	return (tmp);
}
