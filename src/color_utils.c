/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:24:47 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/05 17:39:47 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	str = ft_strdup("0123456789abcdef");
	str1 = ft_strdup("0123456789ABCDEF");
	while (str[i] != c && str1[i] != c && str[i])
		i++;
	free(str);
	free(str1);
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

void	colors_change(t_data *data)
{
	int	red;
	int	green;
	int	blue;
	
	red = 0;
	green = 255;
	blue = 0;
	if (data->z >= 0 || data->z1 >= 0)
	{
		red = 0;
		green = 255;
		blue = 0;
		if (red < 255)
		{
			red += 5 * data->z;
			red <<= 16;
		}
		else 
			red = 255;
		if (green > (3 * data->z))
		{
			green -= 3 * data->z;
			green <<= 8;
		}
		else
			green = 0;
	}
	else
	{
		red = 0;
		green = 255;
		blue = 0;
		if (blue < 255)
		{
			blue -= 5 * data->z;
			blue <<= 16;
		}
		else 
			blue = 255;
		// if (green > (3 * data->z))
		// {
		// 	green += 3 * data->z;
		// 	green <<= 8;
		// }
		// else
		// 	green = 0;
	}
	data->color_default = red + blue + green;
}