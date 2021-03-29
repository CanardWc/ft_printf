#include "includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("coucou nous==%f\n", -0.00032);
	printf("coucou real==%f\n", -0.00032);
	ft_printf("coucou nous==%f\n", 90990.120);
	printf("coucou real==%f\n", 90990.120);
	return (0);


		/* PROBLEMES */
/*
1.5 affiche 0.5
90990.120 devient 90990.119
*/
}
