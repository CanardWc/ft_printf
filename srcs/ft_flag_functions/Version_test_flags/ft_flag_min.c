/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:08:16 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/01 16:42:46 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_flag_minus(char *flag, char *str, char format)
{
	int 	size;
	int 	i;
	int 	y;

	i = 0;
	while (flag[i] && flag[i] != '.')
		size =  atoi(strchr(flag, flag[i++])) > size ?\
			  	atoi(strchr(flag, flag[i -1])) : size ;
	i = 0;
	while(!str[i] && i < size )
		i++;
	while (i >= 1)
	{
		y = 0;
		while (str[i + y])
		{
			str[(i + y) - 1] = str [i + y];
			y++;
		}
	   	if (y != 0)
			str[i + y -1] = '\0';
		i--;
	}
	i = strlen(str);
	while(i < size)
		str[i++] = ' ';
	return(str);	
}

int main()
{
	char *flag = "-50.100d";
	char format = 'd';
	char *str;
	int i; 

	if(!(str = malloc(sizeof(char) * 51)))
		return(0);
	
	i = 0;
	while(i < 46)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	str[i+1] = 'c';
	str[i+2] = 'e';
	str[i+3] = 'f';
	str[i+4] = 'c';
	str[i+5] = '\0';
	printf("str    =1234567890\n");
	printf("str    =%s\n", (str + i +1));
	printf("result =%s", ft_flag_minus(flag, str, format));

	free(str);
	return(0);
}
