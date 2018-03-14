
#include "../includes/libft.h"

size_t	ft_strwlen_n(const wchar_t *s, int n)
{
	size_t	i;

	i = 0;
	if (s && n != 0)
	{
		while (*s != '\0' && n >= ft_wcharlen(*s))
		{
			n -= ft_wcharlen(*s);
			i += ft_wcharlen(*s);
			s++;
		}
	}
	return (i);
}
