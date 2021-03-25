#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct		s_dbl_data
{
	int		sign;
	char		*decimal;
	int		pow;
}			t_dbl_data;

t_dbl_data	ft_dbl_negexp(t_dbl_data data, int exp)
{
	int		add;
	int		div;
	char	*tmp;

	add = 0;
	while (exp++ < 0)
	{
		tmp = data.decimal;
		while (*tmp || add)
		{
			div = 0;
			if (*tmp)
				div = ((*tmp - 48) * 10) / 2;
			*tmp = ((div / 10) + add) + 48;
			add = div % 10;
			tmp++;
		}
	}
	tmp = data.decimal;
	while (*tmp == '0')
		tmp++;
	data.pow = data.decimal - tmp;
	memmove(data.decimal, tmp, strlen(tmp));
	bzero(data.decimal + strlen(tmp), 340 - strlen(tmp));
	return (data);
}

void	ft_posexp_calc(t_dbl_data data, int exp)
{
	char	*tmp;
	int		add;
	int		save;

	while (exp--)
	{
		tmp = data.decimal + 340;
		while (*--tmp || save == 38)
		{
			add = save == 38;
			save = 48;
			if (*tmp && *tmp > '4')
				save = 38;
			if (*tmp)
				*tmp = ((*tmp - 48) * 2) + save + add;
			else
				*tmp = 48 + add;
		}
	}
}

t_dbl_data	ft_dbl_posexp(t_dbl_data data, int exp)
{
	int		size;
	char	*tmp;
	int		pow_s;

	pow_s = data.pow;
	size = strlen(data.decimal);
	memmove(data.decimal + 340 - size, data.decimal, size);
	bzero(data.decimal, size);
	ft_posexp_calc(data, exp);
	tmp = data.decimal;
	while (!*tmp)
		tmp++;
	data.pow = pow_s + strlen(tmp) - size;
	memmove(data.decimal, tmp, strlen(tmp));
	bzero(data.decimal + strlen(tmp), 340 - strlen(tmp));
	return (data);
}

t_dbl_data	ft_getdbl_exponent(t_dbl_data data, int exp)
{
	if (exp < 0)
		return (ft_dbl_negexp(data, exp));
	else if (exp > 0)
		return (ft_dbl_posexp(data, exp));
	return (data);
}
/*
int main()
{
	t_dbl_data	ret;
	t_dbl_data	ret2;
	char		*str = "4";
	t_dbl_pars	pars;
	t_dbl_pars	pars2;

	pars.exp = 2;
	pars2.exp = -1;
	ret.sign = 1;
	ret2.sign = -1;
	ret.pow = 2;
	ret2.pow = -2;
	ret.decimal = (char *)calloc(340, sizeof(char));
	ret2.decimal = (char *)calloc(340, sizeof(char));
	memmove(ret.decimal, str, strlen(str));
	memmove(ret2.decimal, str, strlen(str));
	ret =  ft_getdbl_exponent(ret, pars);
	ret2 =  ft_getdbl_exponent(ret2, pars2);
	dprintf(1, "ret==%s\n", ret.decimal);
	dprintf(1, "ret2==%s\n", ret2.decimal);
}*/
