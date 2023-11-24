/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:35:10 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/04 10:40:34 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_string;
	int		i;
	int		x;

	i = 0;
	x = 0;
	join_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (join_string == NULL)
		return (NULL);
	while (s1[i])
		join_string[x++] = s1[i++];
	i = 0;
	while (s2[i])
		join_string[x++] = s2[i++];
	join_string[x] = '\0';
	return (join_string);
}

// int	main(void)
// {
// 	char 	*s1;

// 	s1 = ft_strjoin("cao e", "");
// 	printf("%s", s1);
// }