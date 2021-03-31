#include <libftprintf.h>

double		ft_get_ap_g(va_list ap, const char *s)
{
	if (ft_search(s, "l"))
		return ((double)va_arg(ap, double));
	else
		return ((double)va_arg(ap, double));
}

int	ft_format_g(t_printf data, t_flags flags, va_list ap)
{
	t_dbl	v;
	int	size;

	size = 1;
	flags.min = 0;
	v = ft_getdbl(ft_get_ap_g(ap, data.s));
	return (data.ret);
	/*

	// on arrondis ici;
	
	//case e

	if (v.pow < -4)
	{
		if (ft_search(data.s, "#"))
			data.s + ft_search(data.s, "#") = '.';
		return(ft_gestion_format_e(des trucs));
	}

	if ((flags.prec < 0 && v.pow > 6) || (v.pow > 0 && v.pow > flags.prec))
	{
		return(ft_gestion_format_e(des trucs));
	}

	//case f

	flags.prec -= v.pow;
	return(ft_gestion_format_f(des trucs));

	*/
}
