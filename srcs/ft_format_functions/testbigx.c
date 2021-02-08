#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int	ft_format_size_bigx(int nb, char *flags)
{
	int	ret;
	char	*tmp;
	int	t_ret;

	tmp = flags;
	ret = 1;
	while ((nb /= 16) > 0)
		ret++;
	t_ret = ret;
	while (*flags && *flags != '.')
		ret = ret < atoi(flags++) ? atoi(flags - 1) : ret;
	if (strchr(tmp, '#') && t_ret + 1 >= ret)
		ret = t_ret + 2;
	if (strchr(tmp, '.') && atoi(strchr(tmp, '.') + 1) >= ret)
		if (strchr(tmp, '#'))
			ret += 2;
	ret++;
	//	if (!(ret.str = ft_calloc(ret.size, sizeof(char))))
	//		return (ret);
	return (ret);
}

int main()
{
	int	i;

	i = ft_format_size_bigx(42, "# 100.100x");
	printf("%d\n", i);
	i = printf("%# 100.100x", 42);
	printf("\n");
	printf("%d\n", i);
}
