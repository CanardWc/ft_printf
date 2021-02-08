#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_format_size_c(char c, char *flags)
{
	int	ret;

	ret = 0;
	while (*flags != '.' && ret == 0 && *flags)
		ret = atoi(flags++);
	ret = ret == 0 ? 2 : ret + 1;
//	if (!(retstr = ft_calloc(ret.size, sizeof(char))))
//		return (ret);
	return (ret);
}

int main()
{
	int	i;

	i = ft_format_size_c(42, ".100c");
	printf("%d\n", i);
	i = printf("%.100c", 42);
	printf("\n");
	printf("%d\n", i);
}
