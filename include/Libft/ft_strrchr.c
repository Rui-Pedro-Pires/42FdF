/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:17:37 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/09 11:10:07 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
		ptr++;
	while (*ptr != (unsigned char)c && ptr != (char *)str)
		ptr--;
	if (*ptr == (unsigned char)c)
		return (ptr);
	return (NULL);
}

// int	main(void)
// {
// 	char s1[] = "cao e gato";
// 	char s2[] = "cao e gato";
// 	printf("%s\n", ft_strrchr(s1, '\0'));
// 	printf("%s", strrchr(s2, '\0'));
// }
