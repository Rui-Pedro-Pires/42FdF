/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:47:48 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/04 14:59:17 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (*dst && i < size)
	{
		dst++;
		i++;
	}
	if (i == size)
		return (i + ft_strlen(src));
	while (src[x])
	{
		if (x < size - i - 1)
			*dst++ = src[x];
		x++;
	}
	*dst = '\0';
	return (i + x);
}

// int	main(void)
// {
// 	char s1[] = "a";
// 	char s2[] = "a";
// 	printf("%d\n", ft_strlcat(s1, s2, 3));
// 	printf("%s", s1);
// }