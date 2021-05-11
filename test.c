#include "includes/libftprintf.h"
#include <stdio.h>
#include <limits.h>

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
	//	while (1)
	//	{
	wchar_t	 empty[] = {0};
	wchar_t	 s[] = {' ', u'ƀ', u'ɏ', u'ɐ', ' ', u'ʯ', ' ', u'ʰ', u'˿', ' ', u'ୟ', ' ', u'௫', ' ', ' ', u'࿚', 0};
	i = ft_printf("this %.9f float", 1.5);
	printf("\n");
	ft_printf("i = %d\n", i);
	i = printf("this %.9f float", 1.5);
	printf("\n");
	ft_printf("i = %d\n", i);
	//		ft_printf("%.8e\n", 23.375094499);
	//		ft_printf("%.9e\n", -5.0299999);
	//		char *lol = malloc(sizeof(char) * 3);
	//		free(lol);
	//	}
	return (0);
}

/* PROBLEMES */
/*
 * Test qu'on fait pas : 3510 - 4000
 *
 */
