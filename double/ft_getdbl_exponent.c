#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct		s_dbl_data
{
	int		sign;
	int		pow;
	char	*decimal;
}					t_dbl_data;

t_dbl_data	ft_dbl_negexp(t_dbl_data ret)
{
	int		add;
	int		div;
	char	*tmp;

	add = 0;
	while (ret.pow++ < 0)
	{
		tmp = ret.decimal;
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
	tmp = ret.decimal;
	while (*tmp == '0')
		tmp++;
	ret.pow = ret.decimal - tmp;
	memmove(ret.decimal, tmp, strlen(tmp));
	bzero(ret.decimal + strlen(tmp), 340 - strlen(tmp));
	return (ret);
}

void	ft_posexp_calc(t_dbl_data ret)
{
	char	*tmp;
	int		add;
	int		save;

	while (ret.pow--)
	{
		tmp = ret.decimal + 340;
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

t_dbl_data	ft_dbl_posexp(t_dbl_data ret)
{
	int		size;
	char	*tmp;
	int		pow_s;

	pow_s = ret.pow;
	size = strlen(ret.decimal);
	memmove(ret.decimal + 340 - size, ret.decimal, size);
	bzero(ret.decimal, size);
	ft_posexp_calc(ret);
	tmp = ret.decimal;
	while (!*tmp)
		tmp++;
	ret.pow = pow_s + strlen(tmp) - size;
	memmove(ret.decimal, tmp, strlen(tmp));
	bzero(ret.decimal + strlen(tmp), 340 - strlen(tmp));
	return (ret);
}

t_dbl_data	ft_getdbl_exponent(t_dbl_data ret)
{
	if (ret.sign < 0)
		return (ft_dbl_negexp(ret));
	else if (ret.sign > 0)
		return (ft_dbl_posexp(ret));
	return (ret);
}

int main()
{
	t_dbl_data	ret;
	t_dbl_data	ret2;
	char		*str = "11";

	ret.sign = 1;
	ret2.sign = -1;
	ret.pow = 2;
	ret2.pow = -2;
	ret.decimal = (char *)calloc(340, sizeof(char));
	ret2.decimal = (char *)calloc(340, sizeof(char));
	memmove(ret.decimal, str, strlen(str));
	memmove(ret2.decimal, str, strlen(str));
	ret =  ft_getdbl_exponent(ret);
	ret2 =  ft_getdbl_exponent(ret2);
	dprintf(1, "ret==%s\n", ret.decimal);
	dprintf(1, "ret2==%s\n", ret2.decimal);
}
