/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:12:22 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/04 15:31:07 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != (unsigned char)c && *ptr)
		ptr++;
	if (*ptr == (unsigned char)c)
		return (ptr);
	return (NULL);
}

// int	main(void)
// {
// 	char s1[] = "cao e gato";
// 	char s2[] = "cao e gato";
// 	printf("%s", ft_strchr(s1, '\0'));
// 	printf("%s", strchr(s2, '\0'));
// }