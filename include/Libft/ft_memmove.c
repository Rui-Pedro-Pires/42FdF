/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:35:00 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/09 11:59:26 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest1;
	unsigned const char	*src1;

	dest1 = dest;
	src1 = src;
	if (!src1 && !dest)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	while (n--)
		dest1[n] = src1[n];
	return (dest);
}

// int	main(void)
// {
// 	// char s1[20];
// 	char s2[] = "animal";
// 	//memmove(s2, s2 + 2, 3);
// 	char *s1 = ft_memmove(s2 + 2, s2, 2);
// 	printf("%s", s1);
// }