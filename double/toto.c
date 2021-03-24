#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef union			s_dbl_pars
{
	unsigned long long	sign : 1;
	unsigned long long	exp : 11;
	unsigned long long	fract : 52;
}				t_dbl_pars;

char	*ft_binary_pow(char *tmp, int i)
{
	int	j;
	int	div;
	int	remnant;

	remnant = 0;
	tmp[0] = '1';
	while (i > 0)
	{
		j = 0;
		while (isdigit(tmp[j]) || remnant)
		{
			if (tmp[j])
				div = ((tmp[j] - '0') * 10) / 2;
			else
				div = 0;
			tmp[j] = ((div / 10) + remnant) + '0';
			remnant = div % 10;
			j++;
		}
		i--;
	}
	//printf("tmp = %s\n", tmp);
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
		/*if (!ret[i])
			add = tmp[i] - '0';
		else
			add = (ret[i] - '0') + (tmp[i] - '0');
		if ((add % 10 + remnant) < 10)
			ret[i] = (add % 10 + remnant) + '0';
		else
			ret[i] = '0';
		remnant = add / 10 ? 1 : 0;*/
	}
	printf("ret = %s\n", ret);
	return (ret);
}

int	main(void)
{
	int	i;
	char	*lol = "1111";
	char	*ret;
	char	*tmp;

	if (!(ret = (char *)calloc(340, sizeof(char))))
		return (0);
	i = 0;
	ret[0] = '1';
	printf("len = %d\n", strlen(lol));
	while (lol[i])
	{
		if (lol[i] == '1')
		{
			if (!(tmp = (char *)calloc(50, sizeof(char))))
			return (0);
			tmp = ft_binary_pow(tmp, i + 1);
			ret = ft_add_tmp(ret, tmp);
			free(tmp);
		}
		i++;
	}
	printf("ret = %s\n", ret);
	return (0);
}
