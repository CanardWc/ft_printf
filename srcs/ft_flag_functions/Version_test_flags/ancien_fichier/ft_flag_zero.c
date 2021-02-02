
#include "ft_printf.h"

int ft_flag_zero(struct format, unsigned char *str)
{
	unsigned char *ret;
	int i;
	int y;

	i = 0;
	if (ft_strlen(str) >= format->value_zero)
		return str;
	if (!(ret = malloc(sizeof(char*(format->value-zero + 1)))))
		return (0);
	while (i < (format->value-zero - strlen(str)))
		ret[i++] = 0;
	while (i < format->value-zero)
		ret[i++] = str[y++];
	i = 0;
	while (ret[i++] == '0')
		if (format->format == "int" && ret[i+1] == '-')
		{	
			ret[i+1] = '0';
			ret[0] = '-';
		}
	return (1);
}
