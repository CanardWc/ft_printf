#include <stdio.h>

typedef union			s_dbl_pars
{
	unsigned long long	sign : 1;
	unsigned long long	exp : 11;
	unsigned long long	fract : 52;
}				t_dbl_pars;

typedef struct			s_dlb_data
{
	int	sign;
	char	*decimal;
	int	pow;
}				t_dbl_data;

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
		while (isdigit(tmp[j]) || remnant != 0)
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
	int	j;
	int	add;
	int	remnant;

	i = strlen(tmp);
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

char	*ft_getdbl_fraction(t_dbl_pars parsed_dbl)
{
	char	*ret;
	char	*tmp;
	int	i;

	if ((ret = (char *)calloc(340, sizeof(char))))
		return (ret);
	i = 0;
	ret[0] = parsed_dbl.exp == 0 ? 0 : 1;
	while (++i < 52)
	{
		if ((parsed_dbl.fract & 0x1))
		{
			if ((tmp = (char *)calloc(50, sizeof(char))))
				return (ret);
			tmp = ft_binary_pow(tmp, i);
			ret = ft_add_tmp(ret, tmp);
			free(tmp);
		}
		parsed_dbl.fract >>= 1;
	}
	return (ret);
}
