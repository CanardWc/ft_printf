/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:21:14 by fgrea             #+#    #+#             */
/*   Updated: 2021/02/12 12:27:31 by edassess         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	if (!(ret = (t_list *)calloc(sizeof(t_list), 1)))
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
