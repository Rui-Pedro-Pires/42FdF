/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:21:04 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/28 16:36:54 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom(float *x, float *y, t_data *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

void	map_move(float *x, float *y, t_data *data)
{
	*x += data->hor;
	*y += data->hey;
}

int	build_img(t_data *data)
{
	char	*ptr;
	
	ptr = NULL;
	data->color = 0xFFFFFF;
	colors_change(data);
	if (data->u < (WIDTH - 1) && data->u >= 0 \
	&& data->v < (HEIGHT - 1) && data->v >= 0)
	{
		ptr = data->img.addr + (int)data->u * (data->img.bpp / 8) \
		+ ((int)data->v * data->img.line_len);
		*(unsigned int *)ptr = data->color;
	}
	return (0);
}

// void	colors_change(t_data *data)
// {
// 	int	red;
// 	int	green;
// 	// int	blue;

// 	green = 255;
// 	red = 0;
// 	if (data->z > 0 || data->z1 > 0)
// 	{
// 		if (red < 255)
// 		{
// 			red = (0x000000 + 255/150*data->z);
// 			red <<= 16;
// 		}
// 	}
// 	if (data->z > 0 || data->z1 > 0)
// 	{
// 		green += (0x000000 - 255/80*data->z + 0);
// 		if (green > 0)
// 		{
// 			green <<= 8;
// 		}
// 		data->color = red + green;
// 	}
// 	// blue = 0;
// // 	if (data->z > 10 || data->z1 > 10)
// // 		data->color = 0x54ae3f;
// // 	if (data->z > 15 || data->z1 > 15)
// // 		data->color = 0x810202;
// }

void	colors_change(t_data *data)
{
	if (data->z >= 0 || data->z1 >= 0)
		data->color = 0x00FFFF;
	if (data->z >= 10 || data->z1 >= 10)
		data->color = 0xFFFF00;
	if (data->z >= 90 || data->z1 >= 90)
		data->color = 0xFF0000;
	if (data->z >= 120 || data->z1 >= 120)
		data->color = 0xFFFFFF;
}