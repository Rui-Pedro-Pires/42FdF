/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:21:37 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/09 12:16:25 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*s1;

	s1 = malloc(nitems * size);
	if (!s1)
		return (NULL);
	ft_bzero(s1, nitems * size);
	return (s1);
}

// int	main(void)
// {
// 	char *s1;

// 	s1 = ft_calloc(4, sizeof(char));
// 	printf("%s", s1);
// }