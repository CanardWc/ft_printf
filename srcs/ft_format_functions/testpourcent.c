#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_format_size_percent(char *flags)
{
	int	ret;
	char		*tmp;

	ret = 2;
	while (*flags && *flags != '.')
		ret = atoi(flags++) > ret ? atoi(flags - 1) + 1 : ret;
//	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
//		return (ret);
	return (ret);
}

int main()
{
	int	i;

	i = ft_format_size_percent(" 10.10%");
	printf("%d\n", i);
	i = printf("% 10.10%");
	printf("\n");
	printf("%d\n", i);
}
