#include <libftprintf.h>

int	ft_format_g(t_printf data, t_flags flags, va_list ap)
{
	t_dbl	v;
	int	size;

	size = 1;
	flags.min = 0;
	v = ft_getdbl(va_arg(ap, double));
	// on arrondis ici;

	//case e

	if (v.pow < -4)
	{
		//	if (ft_search(data.s, "#"))
		//		data.s + ft_search(data.s, "#") = '.';
				flags.prec = 5;
		return(ft_dbl_case_e(data, flags, v));
	}

	if ((flags.prec < 0 && v.pow > 6) || (v.pow > 0 && v.pow > flags.prec))
	{
		flags.prec -= v.pow + 1;
		return(ft_dbl_case_e(data, flags, v));
	}

	//case f

	if (v.pow > 0)
		flags.prec -= v.pow;
	else
		flags.prec += v.pow;
	return(ft_dbl_case_f(data, flags, v));
}
