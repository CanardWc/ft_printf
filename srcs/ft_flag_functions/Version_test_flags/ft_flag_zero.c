
//#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *ft_flag_zero(char *flag, char *str, char format)
{
	int 	size;
	int 	i;
	int 	neg;

	i = 0;
	while (flag[i] && flag[i] != '.')
		size =  atoi(strchr(flag, flag[i++])) > size ?\
			  	atoi(strchr(flag, flag[i -1])) : size ;
	i = 0;	
	while(!str[i] && i < size )
		i++;
	neg  = (format == 'i' || format == 'd') && str[i] == '-' ? 1 : 0;
	i += (int)strlen(str + i) - 1;
	while(str[i] && i > 0)
	{
		str[size--] = str[i];
		str[i--] = '\0';
	}
	i = 0;
	while (!str[i])
		str[i++] = '0';
	str[0] = neg ? '-': '0';
	str[i] = neg ? '0': str[i];
	str[1] = format == 'p' ? 'x': str[1];
	str[i + 1] = format == 'p' ? '0': str[i + 1];
	return (str);
}

int main()
{
	char *flag = "15.100d";
	char format = 'p';
	char *str;
	int i;

	if(!(str = malloc(sizeof(char) * 16)))
		return(0);

	i = 0;

	str[i] = '\0';
	str[i+1] = '\0';
	str[i+2] = '0';
	str[i+3] = 'x';
	str[i+4] = 'm';
	str[i+5] = 'c';
	i += 6;
	while(i <= 16)
	{
		str[i] = '\0';
		i++;
	}
	printf("str    =1234567890\n");
	printf("str    =%s\n", (str + 2));
	printf("result =%s\n", ft_flag_zero(flag, str, format));
	i =0;

	while(i < 15)
		printf("str = %s\n", (str + i++));


	free(str);
	return(0);
}
