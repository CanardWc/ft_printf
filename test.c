#include "includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
int i;
double f;
f = 42.42;
i = 0;
//	while (1)
//	{
//	ft_printf("coucou nous==%.*f\n", -3, -1.041593);
//	printf("coucou real==%.*f\n", -3, -3.141593);
//	ft_printf("coucou nous==%.*f\n", -3, -1.041593);
//	printf("coucou real==%.*f\n", -3, -3.141593);
//	ft_printf("coucou nous==%.*f\n", -3, -1.041593);
//	printf("coucou real==%.*f\n", -3, -3.141593);
//	ft_printf("coucou nous==%#12.0f\n", 0.0003);
//	printf("coucou real==%#12.0f\n", 0.0003);
//
//	ft_printf("coucou nous==%.0f\n", 0.5);
//	printf("coucou real==%.0f\n", 0.5);
/*	
	ft_printf("coucou nous==%.0f\n", 0.5);
	printf("coucou real==%.0f\n", 0.5);
	ft_printf("coucou nous==%.0f\n", 1.5);
	printf("coucou real==%.0f\n", 1.5);
	ft_printf("coucou nous==%.0f\n", 2.5);
	printf("coucou real==%.0f\n", 2.5);
	ft_printf("coucou nous==%.0f\n", 3.5);
	printf("coucou real==%.0f\n", 3.5);
	ft_printf("coucou nous==%.0f\n", 4.5);
	printf("coucou real==%.0f\n", 4.5);
	ft_printf("coucou nous==%.0f\n", 5.5);
	printf("coucou real==%.0f\n", 44.5);
	ft_printf("coucou nous==%.0f\n", 6.5);
	printf("coucou real==%.0f\n", 6.5);
	ft_printf("coucou nous==%.0f\n", 7.5);
	printf("coucou real==%.0f\n", 7.5);
	ft_printf("coucou nous==%.0f\n", 8.5);
	printf("coucou real==%.0f\n", 8.5);
	ft_printf("coucou nous==%.0f\n", 9.5);
	printf("coucou real==%.0f\n", 9.5);
	ft_printf("coucou nous==%.0f\n", 10.5);
	printf("coucou real==%.0f\n", 10.5);
	*/
	ft_printf("%.1f\n", -0.999);
	return (0);
}

		/* PROBLEMES */
/*
90990.120 devient 90990.119
arrondi
des chiffres qui partent en couille
problemes de conversion i think
*/
