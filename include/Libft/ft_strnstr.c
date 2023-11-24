/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:33:49 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/09 10:46:37 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t n)
{
	size_t	len1;

	len1 = ft_strlen(lit);
	if (!(*lit))
		return ((char *)big);
	while (*big && n >= len1)
	{
		if (*big == *lit && ft_strncmp(big, lit, len1) == 0)
			return ((char *)big);
		big++;
		n--;
	}
	return (NULL);
}

//  int	main(void)
//  {
// 	char s1[] = "animais: cao, gato, cabra, vaca!";
// 	char s2[] = "aca";
// 	printf("%s", ft_strnstr(s1, s2, 2));
//  }
