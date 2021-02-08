#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	ft_format_size_e(long double nb, char *flags)
{
	int	ret;
	int		prec;
	int		sign;
	int		nb_exposant;

	ret = 12;
	prec = 0;
	prec = strchr(flags, '.') ? atoi(strchr(flags, '.') + 1) + 6 : 12;
	printf("prec == %d\n", prec);
	sign = nb < 0 ? -1 : 1;
	nb *= sign;
	if (nb > 1)
	{
		while(nb > 10 && nb_exposant <= 110 )
		{
			nb /= 10;
			nb_exposant++;
		}
	}
	else if (nb < 1)
	{
		while(nb < 1 && nb_exposant <= 110)
		{
			nb *= 10;
			nb_exposant++;
		}
	}
	prec = nb_exposant < 106 ? prec : prec + 1;
	if (strchr(flags, '+') || strchr(flags, ' ') || sign == -1)
		prec++;
	while (*(++flags -1))
		ret =  atoi(flags) ? atoi(flags) : ret;
	ret = prec < ret ? ret : prec++;
//	if (!(ret = calloc(ret, sizeof(char))))
//		return (0);
	return (ret);
}


int main()
{
	int	i;

	i = ft_format_size_e(42.42, " 10.2e");
	printf("%d\n", i);
	i = printf("% 10.2e", 42.42);
	printf("\n");
	printf("%d\n", i);
}
