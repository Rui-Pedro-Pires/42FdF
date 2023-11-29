/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:24:47 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/29 16:48:20 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_pos(char c);
int	check_for_colors(char *str);

int	atoi_base(char *str)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i] != ',')
		i++;
	i += 2;
	while (str[i])
	{
		num = num * 16 + get_pos(str[i]);
		i++;
	}
	return (num);
}

int	get_pos(char c)
{
	int		i;
	char	*str;
	char	*str1;

	i = 0;
	str = "0123456789ABCDEF";
	str1 = "0123456789abcdef";
	while (str[i] != c && str1[i] != c)
		i++;
	return (i);
}

int	check_for_colors(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}
