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

t_dbl_data	ft_binary_pow(t_dbl_data tmp, int i)
{
	int	j;
	int	div;
	int	remnant;

	j = 0;
	remnant = 0;
	tmp.decimal[0] = '1';
	while (i > 0)
	{
		while (isdigit(tmp.decimal[j]) || remnant != 0)
		{
			if (tmp.decimal[j])
				div = ((tmp.decimal[j] - '0') * 10) / 2;
			else
				div = 0;
			tmp.decimal[j] = ((div / 10) + remnant) + '0';
			remnant = div % 10;
			j++;
		}
		j = 0;
		i--;
	}
	return (tmp);
}

t_dbl_data	ft_add_tmp(t_dbl_data ret, t_dbl_data tmp)
{
	int	i;
	int	j;
	int	add;
	int	remnant;

	i = strlen(tmp.decimal);
	add = 0;
	remnant = 0;
	while (--i >= 0)
	{
		if (!ret.decimal[i])
			add = tmp.decimal[i] - '0';
		else
			add = (ret.decimal[i] - '0') + (tmp.decimal[i] - '0');
		add = add % 10 + remnant;
		ret.decimal[i] = add < 10 ? (add % 10 + remnant) + '0' : '0';
		remnant = add / 10 ? 1 : 0;
	}
	return (ret);
}

t_dbl_data	ft_get_fraction(t_dbl_pars parsed_dbl)
{
	t_dbl_data	ret;
	t_dbl_data	tmp;
	int		i;

	if ((ret.decimal = (char *)calloc(340, sizeof(char))))
		return (ret);
	i = 0;
	ret.decimal[0] = parsed_dbl.exp == 0 ? 0 : 1;
	while (++i < 52)
	{
		if ((parsed_dbl.fract & 0x1))
		{
			if ((tmp.decimal = (char *)calloc(50, sizeof(char))))
			return (ret);
			tmp = ft_binary_pow(tmp, i);
			ret.decimal = ft_add_tmp(ret, tmp);
			free(tmp.decimal);
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

int	main(void)
{
	int		i;
	char		*lol = "11111111111111111111111111";
	t_dbl_data	ret;
	t_dbl_data	tmp;

	if (!(ret.decimal = (char *)calloc(340, sizeof(char))))
		return (0);
	i = 0;
	ret.decimal[0] = '1';
	printf("len = %d\n", strlen(lol));
	while (lol[i])
	{
		if (lol[i] == '1')
		{
			if (!(tmp.decimal = (char *)calloc(50, sizeof(char))))
			return (0);
			tmp = ft_binary_pow(tmp, i + 1);
			ret = ft_add_tmp(ret, tmp);
			free(tmp.decimal);
		}
		i++;
	}
	printf("ret = %s\n", ret.decimal);
	return (0);
}
