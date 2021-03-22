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

char	*ft_binary_pow(char *tmp, unsigned long long fract, int i);
{

	return (tmp);
}

t_dbl_data	ft_get_fraction(t_dbl_pars parsed_dbl)
{
	t_dbl_data	ret;
	char		tmp[50];
	int		i;

	bzero(tmp, 50);
	if ((ret.decimal = (char *)calloc(340, sizeof(char))))
		return (ret);
	i = 0;
	ret.decimal[0] = parsed_dbl.exp == 0 ? 0 : 1;
	while (++i < 52)
	{
		if ((parsed_dbl.fract & 0x1))
		{
			tmp = ft_binary_pow(tmp, parsed_dbl.fract, i);
			ret.decimal = ft_add_tmp(ret.decimal, tmp);
		}
		parsed_dbl.fract >>= 1;
	}
	return (ret);
}

t_dbl	ft_get_double(double d)
{
	t_dbl_pars	parsed_dbl;
	t_dbl_data	dbl;
	int		i;

	i = 0;
	memcpy(&parsed_dbl, &d, sizeof(double));
	dbl.sign = parsed_dbl.sign == 0 ? -1 : 1;
	while (i < 52)
	{
		if (parsed_dbl.fract & 0x1)

	}
}
