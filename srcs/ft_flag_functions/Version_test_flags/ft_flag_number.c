//#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *push_to_end(char *str ,int size)
{
	int i;


	i = 0;
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
	}
	return(str);
}

char	*ft_flag_number(char *flag, char *str, char format)
{
	int 	size;
	int 	i;
	int 	y;

	i = 0;
	while (flag[i] && flag[i] != '.')
		size =  atoi(strchr(flag, flag[i++])) > size ?\
			  	atoi(strchr(flag, flag[i -1])) : size ;
	
	printf("i    =%d\n", i);
	str = push_to_end(str, size);
	i = 0;
	while(!str[i] && i < size )
		str[i++] = ' ';
	return(str);
}

int main()
{
	char *flag = "-15d";
	char format = 'd';
	char *str;
	int i;

	if(!(str = malloc(sizeof(char) * 16)))
		return(0);

	i = 0;
	str[i] = '\0';
	str[i+1] = 'c';
	str[i+2] = 'e';
	str[i+3] = 'f';
	str[i+4] = 'c';
	i += 5; 
	while(i <= 16)
	{
		str[i] = '\0';
		i++;
	}
	str[i+5] = '\0';
	printf("str    =1234567890\n");
	printf("str    =%s\n", (str  + 1));
	printf("result =%s\n", ft_flag_number(flag, str, format));

	i=0;
	while(i <= 16)
		printf("str    =%s\n", (str  + i++));
	
	free(str);
	return(0);
}
