/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 10:27:09 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/02 14:24:38 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
//cspdiuxX%
int main()
{
	int 	i = +10;
	char	*s = "salut";
	char	c = 'c';
	double  f = 1.1;

/*printf("\tMoins\n");

printf("%-100c\n", c);
printf("%-100s\n", s);
printf("%-100p\n", &s);
printf("%-100d\n", i);
printf("%-100i\n", i);
printf("%-100u\n", i);
printf("%-100x\n", i);
printf("%-100X\n", i);
printf("%-100%\n");
printf("%-100e\n",f);
printf("%-100f\n",f);
printf("%-100g\n\n",f);

printf("%-c\n", c);
printf("%-s\n", s);
printf("%-p\n", &s);
printf("%-d\n", i);
printf("%-i\n", i);
printf("%-u\n", i);
printf("%-x\n", i);
printf("%-X\n", i);
printf("%-%\n");
printf("%-e\n",f);
printf("%-f\n",f);
printf("%-g\n\n",f);



printf("\tZero\n");

printf("%0100c\n", c);
printf("%0100s\n", s);
printf("%0100p\n", &s);
printf("%0100d\n", i);
printf("%0100i\n", i);
printf("%0100u\n", i);
printf("%0100x\n", i);
printf("%0100X\n", i);
printf("%0100%\n",i);
printf("%0100e\n",f);
printf("%0100f\n",f);
printf("%0100g\n\n",f);

printf("%c\n", c);
printf("%s\n", s);
printf("%p\n", &s);
printf("%d\n", i);
printf("%i\n", i);
printf("%u\n", i);
printf("%x\n", i);
printf("%X\n", i);
printf("%%\n");
printf("%e\n",f);
printf("%f\n",f);
printf("%g\n\n",f);



printf("\tPlus\n");

printf("%+100c\n", c);
printf("%+100s\n", s);
printf("%+100p\n", &s);
printf("%+100d\n", i);
printf("%+100i\n", i);
printf("%+100u\n", i);
printf("%+100x\n", i);
printf("%+100X\n", i);
printf("%+0100%\n");
printf("%+100e\n",f);
printf("%+100f\n",f);
printf("%+100g\n\n",f);

printf("%+c\n", c);
printf("%+s\n", s);
printf("%+p\n", &s);
printf("%+d\n", i);
printf("%+i\n", i);
printf("%+u\n", i);
printf("%+x\n", i);
printf("%+X\n", i);
printf("%+%\n");
printf("%+e\n",f);
printf("%+f\n",f);
printf("%+g\n\n",f);



printf("\tEspace\n");

printf("% 100c\n", c);
printf("% 100s\n", s);
printf("% 100p\n", &s);
printf("% 100d\n", i);
printf("% 100i\n", i);
printf("% 100u\n", i);
printf("% 100x\n", i);
printf("% 100X\n", i);
printf("% 0100%\n");
printf("% 100e\n",f);
printf("% 100f\n",f);
printf("% 100g\n\n",f);

printf("% 0c\n", c);
printf("% 0s\n", s);
printf("% 0p\n", &s);
printf("% 0d\n", i);
printf("% 0i\n", i);
printf("% 0u\n", i);
printf("% 0x\n", i);
printf("% 0X\n", i);
printf("% 0%\n\n");
printf("% e\n",f);
printf("% f\n",f);
printf("% g\n\n",f)*/;



printf("\tHash\n");
printf("%#100c\n", c);
printf("%100c\n", c);
printf("%#100s\n", s);
printf("%100s\n", s);
printf("%#100p\n", &s);
printf("%100p\n", &s);
printf("%#100d\n", i);
printf("%100d\n", i);
printf("%#100i\n", i);
printf("%100i\n", i);
printf("%#100u\n", i);
printf("%100i\n", i);
printf("%#100x\n", i);
printf("%100x\n", i);
printf("%#100X\n", i);
printf("%100X\n", i);
printf("%# 100%\n");
printf("% 100%\n");
printf("%#100e\n",f);
printf("%100e\n",f);
printf("%#100f\n",f);
printf("%100f\n",f);
printf("%#100g\n",f);
printf("%100g\n\n",f);

printf("%#c\n", c);
printf("%#s\n", s);
printf("%#p\n", &s);
printf("%#d\n", i);
printf("%#i\n", i);
printf("%#u\n", i);
printf("%#x\n", i);
printf("%#X\n", i);
printf("%#%\n");
printf("%#e\n",f);
printf("%#f\n\n",f);
printf("10 == %#g\n",10.0);
printf("%#g\n",0.1);
printf("10000 == %#g\n",100.0);
printf("%g\n",0.0001);
printf("%#g\n",0.0001);
printf("%#g\n",1.101);
printf("%#g\n\n",f);

}
