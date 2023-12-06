/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:12:18 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/06 10:40:16 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenham(t_data *data, double x1, double y1)
{
	data->u = data->x;
	data->v = data->y;
	data->z = data->map[data->y + (data->height / 2)] \
	[data->x + (data->width / 2)].z;
	data->z1 = data->map[(int)y1 + (data->height / 2)] \
	[(int)x1 + (data->width / 2)].z;
	data->color_default = data->map[data->y + (data->height / 2)] \
	[data->x + (data->width / 2)].color;
	colors_change(data);
	rotation(data, &x1, &y1);
	zoom(&x1, &y1, data);
	map_move(&x1, &y1, data);
	data->x_step = x1 - data->u;
	data->y_step = y1 - data->v;
	data->max = max_step(positive(data->x_step), positive(data->y_step));
	data->x_step /= data->max;
	data->y_step /= data->max;
	while ((int)(data->u - x1) || (int)(data->v - y1))
	{
		build_img(data);
		data->u += data->x_step;
		data->v += data->y_step;
	}
}

int	build_img(t_data *data)
{
	char	*ptr;

	ptr = NULL;
	if (data->u < (WIDTH - 200) && data->u >= 0 \
	&& data->v < (HEIGHT) && data->v >= 0)
	{
		ptr = data->img.addr + (int)data->u * (data->img.bpp / 8) \
		+ ((int)data->v * data->img.line_len);
		*(unsigned int *)ptr = data->color_default;
	}
	return (0);
}

float	max_step(float x_step, float y_step)
{
	if (x_step > y_step)
		return (x_step);
	else
		return (y_step);
}

float	positive(float n)
{
	if (n < 0)
		return (n *= -1);
	return (n);
}
