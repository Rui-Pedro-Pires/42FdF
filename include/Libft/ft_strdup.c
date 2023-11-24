/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:21:33 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/04 11:07:30 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = malloc (sizeof(char) * ft_strlen(string) + 1);
	if (s1 == NULL)
		return (NULL);
	while (string[i])
	{
		s1[i] = string[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// int	main(void)
// {
// 	char *s1;
// 	s1 = ft_strdup("cao e gato");
// 	printf("%s", s1);
// }