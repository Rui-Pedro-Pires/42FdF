/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:19:01 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/03 12:21:58 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	c1;

	c1 = c;
	s1 = str;
	while (n--)
		*s1++ = c1;
	return (str);
}

// int	main(void)
// {
// 	char s1[] = "cao e gato"; 
// 	ft_memset(s1, 'h', 4);
// 	printf("%s", s1);
// }