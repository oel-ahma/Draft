/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:55:21 by oel-ahma          #+#    #+#             */
/*   Updated: 2019/10/29 15:16:27 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*before;
	t_list	*start;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		before = new;
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		before->next = new;
		lst = lst->next;
	}
	return (start);
}
