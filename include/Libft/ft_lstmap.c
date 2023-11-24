/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:52:21 by inessilva         #+#    #+#             */
/*   Updated: 2023/10/09 15:08:02 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listt	*ft_lstmap(t_listt *lst, void *(*f)(void *), void (*del)(void *))
{
	t_listt	*new_list;
	t_listt	*tail;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (NULL);
	tail = new_list;
	lst = lst->next;
	while (lst)
	{
		tail->next = ft_lstnew(f(lst->content));
		if (!tail->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
		tail = tail->next;
	}
	tail->next = NULL;
	return (new_list);
}
