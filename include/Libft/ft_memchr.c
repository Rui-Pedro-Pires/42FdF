/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:15:40 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/09 12:01:29 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned const char	*str1;
	unsigned char		c1;

	c1 = c;
	str1 = str;
	while (n--)
	{
		if (*str1 == c1)
			return ((void *)str1);
		str1++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	int	i;
// 	char s1[] = "cao e gato";
// 	int a1[] = {1, 2, 3, 4, 5, 6, 7};
// 	int *a2 = ft_memchr(a1, 2, 4);
// 	int *a3 = memchr(a1, 2, 4);
// 	char *s2 = ft_memchr(s1, 'h', 2);
// 	char *s3 = memchr(s1, 'h', 2);
// 	printf("%s\n", s2);
// 	printf("%s\n", s3);
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("Array a2:%d\n", a2[i]);
// 		printf("Array a3:%d\n", a3[i]);
// 		i++;
// 	}
// }