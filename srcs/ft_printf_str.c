
#include "../includes/ft_printf.h"

void	ft_printf_putstr(char const *s)
{
	if (s == NULL)
		ft_putstr("(null)");
	if (s)
		ft_putstr(s);
}

void	ft_printf_putwstr(wchar_t const *s)
{
	if (s == NULL)
		ft_putstr("(null)");
	if (s)
		ft_putwstr(s);
}

int		ft_printf_strlen(const char *s)
{
	if (s == NULL)
		return (6);
	if (s)
		return (ft_strlen(s));
	return (0);
}

int		ft_printf_strwlen(const wchar_t *s)
{
	if (s == NULL)
		return (6);
	if (s)
		return (ft_strwlen(s));
	return (0);
}
