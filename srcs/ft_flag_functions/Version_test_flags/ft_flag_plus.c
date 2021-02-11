//#include <libftprintf.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_flag_plus(char *flag, char *str, char format)
{
	int i;

	i = 0;
	if (!(format == 'd' || format == 'i' || format == 'e' || format == 'f' || format == 'g'))
		return(str);
	while(!str[i])
		i++;
	if (str[i] != '-')
		str[i -1] = '+';
	return(str);
}

int main()
{
	char *flag = "15.100d";
	char format = 'd';
	char *str;
	int i;

	if(!(str = malloc(sizeof(char) * 16)))
		return(0);

	i = 0;

	str[i] = '\0';
	str[i+1] = '\0';
	str[i+2] = '-';
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
	printf("result =%s\n", ft_flag_plus(flag, str, format));
	i =0;

	while(i < 15)
		printf("str = %s\n", (str + i++));


	free(str);
	return(0);
}
