
//#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *push_to_end(char *str, int prec,int width)
{
	int i;
	int size;

	
	i = 0;
	size = prec > width ? prec : width;
	while (!str[i])
		i++;
	while(str[i])
		i++;
	while (str[i -1] && i >= 0)
	{
		str[size] = str[i - 1];
		str[i-1] = '\0';
		i--;
		size--;
	//	printf("i = %d\n", i);
	}
	return(str);
}

char *fill_zero(char *str)
{
	int i;

	i = 0;
	while(!str[i])
		str[i++] = '0';
	return(str);
}

char *fill_space(char *str)
{
	int i;

	i = 0;
	while(!str[i])
		str[i++] = ' ';
	return(str);
}

char *finish(char *str, char format)
{
	int i;

	while (!str[i] || str[i] == ' ' || str[i] == '0')
		i++;
	//printf("i = %d, c = %c\n",i,str[i]);
	str[0] = str[i - 1] == '-'? '-' : str[0];
	str[i - 1] = str[i - 1] == '-' ? '0' : str[i - 1];
	str[1] = format == 'p' ? 'x' : str[1];
	str[i + 1] = format == 'p' ? '0' : str[i + 1];
	return (str);	
}

char *ft_flag_zero(char *flag, char *str, char format)
{
	int		prec;
	int		width;
	int 	i;

	i = 0;
	prec = 0;
	width = 0;

	while (*flag && *flag != '.')
		if (*flag)
			width =  atoi(flag++) > width ?\
					 atoi(flag - 1) : width ;
	while (*flag)
		if (*flag)
			prec =  atoi(flag++) > prec ?\
					 atoi(flag - 1) : prec ;
	str = push_to_end(str, prec, width);
	if (width < prec)
		str = fill_space(str);
	else
	{	
		str = fill_zero(str);
		str = finish(str, format);
	}
	return(str);
}


int main()
{
	char *flag = "%10.10d";
	char format = 'i';
	char *str;
	int i;

	if(!(str = malloc(sizeof(char) * 16)))
		return(0);

	i = 0;

	str[i] = '\0';
	str[i+1] = '-';
	str[i+2] = '3';
	str[i+3] = '\0';
	str[i+4] = '\0';
	str[i+5] = '\0';
	i += 6;
	while(i <= 16)
	{
		str[i] = '\0';
		i++;
	}
	printf("str    =1234567890\n");
	printf("str    =%s\n", (str + 1));
	printf("str = |% 05.3i|\n", 42 );
	printf("str = |% 03.5i|\n", 42 );
	printf("str = |% 05i|\n", 42 );

	printf("        =123456789\n");
	printf("result 1=|%s|\n", ft_flag_zero("05.3i", str, format));
		i = 0;

	str[i] = '\0';
	str[i+1] = '-';
	str[i+2] = '3';
	str[i+3] = '\0';
	str[i+4] = '\0';
	str[i+5] = '\0';
	i += 6;
	while(i <= 16)
	{
		str[i] = '\0';
		i++;
	}
	printf("result 2=|%s|\n", ft_flag_zero("03.5i", str, format));
		i = 0;

	str[i] = '\0';
	str[i+1] = '-';
	str[i+2] = '3';
	str[i+3] = '\0';
	str[i+4] = '\0';
	str[i+5] = '\0';
	i += 6;
	while(i <= 16)
	{
		str[i] = '\0';
		i++;
	}
	printf("result 3=|%s|\n", ft_flag_zero("05i", str, format));
	printf("result 3=|%05i|\n", -3);
	i =0;

	while(i < 16)
		printf("str = %s\n", (str + i++));


	free(str);
	return(0);
}
