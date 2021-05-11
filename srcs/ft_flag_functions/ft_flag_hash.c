
#include <libftprintf.h>

const char	*g_hash[] = {"0x", "0x", "0X", "0"};
/*
char	*ft_flag_hash_g(char *str, int size)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (!str[i])
		i++;
	while (str[i])
	{
		str[y++] = str[i];
		str[i++] = '\0';
	}
	i = 0;
	while (i < 7)
		if (str[i++] == '\0')
			str[i - 1] = '0';
	i = 0;
	y = size - 7;
	while (str[i])
	{
		str[y++] = str[i];
		str[i++] = '\0';
	}
	return (str);
}
*/

void	ft_flag_hash(char format)
{
	char	*form;
	char	*good_hash;

	form = "pxXo";
	good_hash = (char *)g_hash[ft_strchr(form, format) - form];
	if (ft_strchr(form, format))
		ft_putstr_fd(good_hash, 1);
}
