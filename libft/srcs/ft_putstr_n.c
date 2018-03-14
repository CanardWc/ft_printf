
#include "../includes/libft.h"

void	ft_putstr_n(const char *s, int n)
{
	int i;

	i = 0;
	while (i < n && s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
