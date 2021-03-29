#include <libftprintf.h>

char	*ft_binary_pow(char *tmp, int i)
{
	int	j;
	int	div;
	int	remnant;

	j = 0;
	remnant = 0;
	tmp[0] = '1';
	while (i > 0)
	{
		while (ft_isdigit(tmp[j]) || remnant != 0)
		{
			if (tmp[j])
				div = ((tmp[j] - '0') * 10) / 2;
			else
				div = 0;
			tmp[j] = ((div / 10) + remnant) + '0';
			remnant = div % 10;
			j++;
		}
		j = 0;
		i--;
	}
	return (tmp);
}

char	*ft_add_tmp(char *ret, char *tmp)
{
	int	i;
	int	add;
	int	remnant;

	i = ft_strlen(tmp);
	add = 0;
	remnant = 0;
	while (--i >= 0)
	{
		add = ret[i] ? ret[i] - '0' : 0;
		add += tmp[i] - '0' + remnant;
		ret[i] = add % 10 + '0';
		remnant = add / 10;
	}
	return (ret);
}

char	*ft_getdbl_fraction(unsigned long long parsed_dbl, int exp)
{
	char	*ret;
	char	*tmp;
	int	i;
	int	y;

	y = 1;
	if (!(ret = (char *)ft_calloc(2000, sizeof(char))))
		return (ret);
	i = 11;
	ret[0] = exp == 0 ? '0' : '1';
	while (++i < 64)
	{
		if ((parsed_dbl >> (63 - i) & 1))
		{
			if (!(tmp = (char *)ft_calloc(50, sizeof(char))))
				return (ret);
			tmp = ft_binary_pow(tmp, y);
			ret = ft_add_tmp(ret, tmp);
			free(tmp);
		}
		y++;
	}
	return (ret);
}
