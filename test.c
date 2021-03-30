#include "includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("coucou nous==%.3f\n", 0.0);
	printf("coucou real==%.3f\n", 0.0);
//	ft_printf("coucou nous==%#12.0f\n", 0.0003);
//	printf("coucou real==%#12.0f\n", 0.0003);
	return (0);


		/* PROBLEMES */
/*
90990.120 devient 90990.119
arrondi
des chiffres qui partent en couille
problemes de conversion i think
*/
}
