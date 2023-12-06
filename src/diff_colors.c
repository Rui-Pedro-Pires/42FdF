/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diff_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:46:17 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/06 13:34:25 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	colors1(t_data *data)
{
	int	red;
	int	green;
	int	blue;

	red = 0;
	green = 255;
	blue = 0;
	if (red < 255)
	{
		red += data->max_z * data->z1;
		red <<= 16;
	}
	else 
		red = 255;
	if (green > (data->max_z * 0.2 * data->z1))
	{
		green -= data->max_z * 0.2 * data->z1;
		green <<= 8;
	}
	else
		green = 0;
	data->color_default = red + blue + green;
}

void	colors2(t_data *data)
{
	int	red;
	int	green;
	int	blue;

	red = 0;
	green = 255;
	blue = 0;
	if (blue < 255)
		blue -= data->min_z * data->z1;
	else 
		blue = 255;
	if (red < 255)
	{
		red += data->min_z * 0.2 * data->z1;
		red <<= 16;
	}
	else
		red = 255;
	data->color_default = red + blue + green;
}

void	colors3(t_data *data)
{
	int	red;
	int	green;
	int	blue;

	red = 0;
	green = 255;
	blue = 100;
	if (red < 240)
	{
		red += data->max_z * data->z1;
		red <<= 16;
	}
	else 
		red = 255;
	if (green > (data->max_z * 0.2 * data->z1))
	{
		green -= data->max_z * 0.2 * data->z1;
		green <<= 8;
	}
	else
		green = 0;
	data->color_default = red + blue + green;
}

void	colors4(t_data *data)
{
	int	red;
	int	green;
	int	blue;

	red = 0;
	green = 255;
	blue = 100;
	if (blue < 255)
		blue -= data->min_z * data->z1;
	else 
		blue = 255;
	if (red < (255 - (data->min_z * 0.2 * data->z1)))
	{
		red += data->min_z * 0.2 * data->z1;
		red <<= 16;
	}
	else
		red = 255;
	data->color_default = red + blue + green;
}
