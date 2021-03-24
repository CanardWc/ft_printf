#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_dbl_data	ft_getdbl_exponent(t_dbl_data ret)
{
	if (pow < 0)
		return (ft_dbl_negexp(ret));
	else if (pow > 0)
		return (ft_dbl_posexp(ret));
	else
		return (ret);
}

t_dbl_data	ft_dbl_posexp(t_dbl_data ret)
{
	int		size;
	char	*tmp;
	int		save;
	int		add;

	size = strlen(ret.decimal);
	memmove(ret.decimal + 340 - size, ret.decimal, size);
	bzero(ret.decimal, size);
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
	while (!*ret.decimal)
		ret.decimal++;
	ret.pow = strlen(ret.decimal) - size;
	return (ret);
}

int main()
{
	char *s;
	char *str = "3257";

	s = calloc(340, (sizeof(char)));
	memcpy(s, str, strlen(str));
	printf("%s\n", ft_div(s, 3));
}
