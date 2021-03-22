#include <libftprintf.h>

const char	*form = "cspdiuoxXnfge%";

static t_flags	ft_number(const char *s, va_list ap, t_flags flags)
{
	char	*ignore = "# +";

	while (ft_strchr(ignore, *s))
		s++;
	if (*s == '*' || ft_strchr("1234567689", *s))
		flags.nbr = *s == '*' ? va_arg(ap, int) : ft_atoi(s);
	if (flags.nbr < 0)
	{
		flags.min = flags.nbr;
		flags.nbr = 0;
	}
	return (flags);
}

static t_flags	ft_min(const char *s, va_list ap, t_flags flags)
{
	char	*ignore = "# +0-";

	while (!ft_strchr(form, *s) && !ft_strchr("-.", *s))
		s++;
	if (*s++ == '-')
	{
		while (ft_strchr(ignore, *s))
			s++;
		flags.min = *s == '*' ? va_arg(ap, int) : ft_atoi(s);
	}
	return (flags);
}

static t_flags	ft_prec(const char *s, va_list ap, t_flags flags)
{
	while (!ft_strchr(form, *s) && *s != '.')
		s++;
	if (*s++ == '.')
		flags.prec = *s == '*' ? va_arg(ap, int) : ft_atoi(s);
	if (flags.prec < 0)
		flags.prec = -1;
	return (flags);
}

static t_flags	ft_zero(const char *s, va_list ap, t_flags flags)
{
	char	*forms = "0-.cspdiuoxXnfge%";
	char	*ignore = "# +0";

	while (!ft_strchr(forms, *s))
		s++;
	if (*s++ == '0')
	{
		while (ft_strchr(ignore, *s))
			s++;
		flags.zero = *s == '*' ? va_arg(ap, int) : ft_atoi(s);	
	}
	if (flags.zero < 0)
	{
		flags.min = flags.zero;
		flags.zero = 0;
	}
	return (flags);
}

#include <stdio.h>

t_flags		ft_flag_asterisk(const char *s, va_list ap)
{
	t_flags	flags;

	flags.nbr = 0;
	flags.min = 0;
	flags.prec = -1;
	flags.zero = 0;
	flags = ft_min(++s, ap, flags);
	if (flags.min == 0)
		flags = ft_number(s, ap, flags);
	if (flags.min == 0 && flags.nbr == 0)
		flags = ft_zero(s, ap, flags);
	flags = ft_prec(s, ap, flags);
	if (flags.prec > -1 && flags.zero > 0)
	{
		flags.nbr = flags.zero;
		flags.zero = 0;
	}
	flags.min *= flags.min < 0 ? -1 : 1;
	//printf("nbr = %d, min = %d, zero = %d, prec = %d\n", flags.nbr, flags.min, flags.zero, flags.prec);
	return (flags);
}
