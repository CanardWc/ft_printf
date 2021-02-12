#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	ft_format_size_u(unsigned int i, char *flags)
{
	int	ret;
	int	tmp;

	ret = 1;
	tmp = 1;
	while ((i /= 10) > 0)
		tmp++;
	while (*flags && *flags != '.')
		ret = ret < atoi(flags++) ? atoi(flags - 1) : ret;
	tmp = atoi(strchr(flags, '.') + 1) > tmp ? atoi(strchr(flags, '.') + 1) : tmp;
	ret = ret > tmp ? ret + 1 : tmp + 1;
//	if(!(ret.str = ft_calloc(ret.size, sizeof(char))))
//		return (ret);
	return (ret);
}


int main()
{
	int	i;

	i = ft_format_size_u(12, "1.20u");
	printf("%d\n", i);
	i = printf("%1.20u", 12);
	printf("\n");
	printf("%d\n", i);
}