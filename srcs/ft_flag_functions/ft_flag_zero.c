/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:13:19 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/08 17:13:23 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			width = ft_ atoi(flag++) > width ?\
					ft_atoi(flag - 1) : width ;
	while (*flag)
		if (*flag)
			prec =  ft_atoi(flag++) > prec ?\
					 ft_atoi(flag - 1) : prec ;
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
