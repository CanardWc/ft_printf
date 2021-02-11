#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	ft_format_size_s(char *s, char *flags)
{
	int	ret;
	int	prec;

	ret = 0;
	prec = strchr(flags, '.') ? atoi(strchr(flags, '.') + 1) : \
		   strlen(s);
	prec = prec > (int)strlen(s) ? (int)strlen(s) : prec;
	while (*flags && *flags != '.')
	ret = atoi(flags++) > ret ? atoi(flags - 1) : ret;
	ret = ret < prec ? prec + 1 : ret + 1;
//	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
//		return (ret);
	return (ret);
}
int main()
{
	int	i;

	i = ft_format_size_s("bonjour", "2.2s");
	printf("%d\n", i);
	i = printf("%2.2s", "bonjour");
	printf("\n");
	printf("%d\n", i);
}
