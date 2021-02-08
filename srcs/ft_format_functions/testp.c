#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	ft_format_size_p(unsigned long int nb, char *flags)
{
	int		ret;
	int		i;
	int		prec;

	flags = (void *)flags;
	ret = 0;
	prec = strchr(flags, '.') ? atoi(strchr(flags, '.') + 1) : 0;
	i = 1;
	while ((nb = nb >> 4)  > 0)
		i++;
	while (*flags && *flags != '.')
		ret = atoi(flags++) > ret ? atoi(flags - 1) : ret;
	i = prec > i ? prec : i;
	ret = ret < i + 2 ? i + 3 : ret + 1;
//	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
//		return (ret);
	return (ret);
}

int main()
{
	int	i;
	char *s;

	s = "bonjour";
	i = ft_format_size_p((unsigned long int)s, "15.13p");
	printf("%d\n", i);
	printf("%lx\n", (unsigned long int)s);
	i = printf("%15.13p", s);
	printf("\n");
	printf("%d\n", i);
}
