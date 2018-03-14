
#include "../includes/libft.h"

void	ft_putwstr(wchar_t const *str)
{
	while (*str)
		ft_putwchar(*str++);
}
