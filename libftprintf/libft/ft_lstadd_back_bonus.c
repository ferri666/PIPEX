/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffons-ti <ffons-ti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:36:18 by ffons-ti          #+#    #+#             */
/*   Updated: 2022/11/29 11:57:24 by ffons-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *_new)
{
	t_list	*list;

	if (!lst || !_new)
		return ;
	list = *lst;
	if (!*lst)
	{
		*lst = _new;
		return ;
	}
	while (list)
	{
		if (list->next == NULL)
		{
			list->next = _new;
			break ;
		}
		list = list->next;
	}
}
