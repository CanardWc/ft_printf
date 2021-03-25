/*#include <stdio.h>

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
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

char	*ft_getdbl_fraction(unsigned long long parsed_dbl, int exp)
{
	char	*ret;
	char	*tmp;
	int	i;
	int	y;

	y = 1;
	if (!(ret = (char *)calloc(340, sizeof(char))))
		return (ret);
	i = 11;
	ret[0] = exp == 0 ? '0' : '1';
	while (++i < 64)
	{
		if ((parsed_dbl >> (63 - i) & 1))
		{
			printf("1");
			if (!(tmp = (char *)calloc(50, sizeof(char))))
				return (ret);
			tmp = ft_binary_pow(tmp, y);
			ret = ft_add_tmp(ret, tmp);
			free(tmp);
		}
		else
			printf("0");
		y++;
	}
	printf("\n");
	printf("ret = %s\n", ret);
	return (ret);
}
