/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:36:43 by inessilva         #+#    #+#             */
/*   Updated: 2023/10/09 10:46:10 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_listt **lst, t_listt *new)
{
	t_listt	*tmp1;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp1 = *lst;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	tmp1->next = new;
}
