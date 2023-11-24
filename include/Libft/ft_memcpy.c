/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 12:41:36 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/09 11:57:30 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest1;
	unsigned const char	*src1;

	dest1 = dest;
	src1 = src;
	if (!src1 && !dest)
		return (NULL);
	while (n--)
	{
		*dest1 = *src1;
		dest1++;
		src1++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char s1[] = "cao e gato";
// 	char s2[] = "";
// 	char *s3 = ft_memcpy(s1, s2, 3);
// 	printf("%s", s3);
// }