//#include <libftprintf.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *ft_flag_hash_g(char *str, int size)
{
	int i;
	int y;

	i = 0;
	y = 0;	
	while(!str[i])
		i++;
	while (str[i])
	{
		str[y++] = str[i];
		str[i++] = '\0';
	}
	i = 0;
	while(i < 7)
		if(str[i++] == '\0')
			str[i - 1] = '0';
	i = 0;
	y = size -7;
	while(str[i])
	{
		str[y++] = str[i];
		str[i++] = '\0';
	}	
	return(str);
}

char *ft_flag_hash_x(char *str)
{
	int i;

	i = 0;
	while(!str[i])
		i++;
	str[i - 1] = 'x';
	str[i - 2] = '0';
	return(str);
}

char *ft_flag_hash_X(char *str)
{
	int i;

	i = 0;
	while(!str[i])
		i++;
	str[i - 1] = 'X';
	str[i - 2] = '0';
	return(str);
}

char	*ft_flag_hash(char *flag, char *str, char format)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (flag[i] && flag[i] != '.')
		size =  atoi(strchr(flag, flag[i++])) > size ?\
			  	atoi(strchr(flag, flag[i -1])) : size ;
	if (format == 'g')
		return(ft_flag_hash_g(str, size));
	if (format == 'x')
		return(ft_flag_hash_x(str));
	if (format == 'X')
		return(ft_flag_hash_X(str));
	return(str);
}

int main()
{
	char *flag = "-15.100d";
	char format = 'g';
	char *str;
	int i;

	if(!(str = malloc(sizeof(char) * 16)))
		return(0);

	i = 0;
	while(i < 46)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	str[i+1] = 'c';
	str[i+2] = 'c';
	str[i+3] = 'f';
	str[i+4] = '\0';
	str[i+5] = '\0';
	printf("str    =1234567890\n");
	printf("str    =%s\n", (str + i +1));
	printf("result =%s\n", ft_flag_hash(flag, str, format));

	i = 0;
	while (i < 16)
	{
		printf("str    =%s\n", (str + i++));	
	}
	free(str);
	return(0);
}
