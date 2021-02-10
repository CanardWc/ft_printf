/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrochet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:13:31 by mrochet           #+#    #+#             */
/*   Updated: 2021/02/10 14:55:46 by mrochet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

static char *push_to_end(char *str ,int size)
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

	(void)format;
	i = 0;
	while (flag[i] && flag[i] != '.')
		size =  ft_atoi(flag + i++) > size ?\
			  	ft_atoi(flag + i - 1) : size ;
	str = push_to_end(str, size);
	i = 0;
	while(!str[i] && i < size )
		str[i++] = ' ';
	return(str);
}
