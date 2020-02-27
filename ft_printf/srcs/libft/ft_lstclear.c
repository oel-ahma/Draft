/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:44:14 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/10/29 15:08:05 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*list;
	t_list	*tmp;

	list = *lst;
	tmp = NULL;
	if (lst == NULL || *lst == NULL)
		return ;
	while (list)
	{
		if (list->next)
			tmp = list->next;
		else
			tmp = NULL;
		del(list->content);
		free(list);
		list = tmp;
	}
	*lst = NULL;
}
