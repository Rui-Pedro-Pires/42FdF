/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:08:13 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/03 12:20:39 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	rec;
	int	dest;

	i = 0;
	rec = 0;
	dest = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		rec = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		dest = dest * 10 + (str[i] - '0');
		i++;
	}
	if (rec == 1)
		return (dest *= -1);
	return (dest);
}

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("         3647"));
// 	printf("%d", atoi("   2145"));
// }
