/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:12:18 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/29 16:31:53 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenhaim(t_data *data, double x1, double y1)
{
	data->u = data->x;
	data->v = data->y;
	data->z = data->map[data->y + (data->height / 2)] \
	[data->x + (data->width / 2)].z;
	data->z1 = data->map[(int)y1 + (data->height / 2)] \
	[(int)x1 + (data->width / 2)].z;
	data->color = data->map[data->y + (data->height / 2)] \
	[data->x + (data->width / 2)].color;
	isometric(&data->u, &data->v, &data->z, data);
	isometric(&x1, &y1, &data->z1, data);
	zoom(&data->u, &data->v, data);
	zoom(&x1, &y1, data);
	map_move(&data->u, &data->v, data);
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

void	bresenhaim_2d(t_data *data, double x1, double y1)
{
	data->u = data->x;
	data->v = data->y;
	data->z = data->map[data->y + (data->height / 2)] \
	[data->x + (data->width / 2)].z;
	data->z1 = data->map[(int)y1 + (data->height / 2)] \
	[(int)x1 + (data->width / 2)].z;
	data->color = data->map[data->y + (data->height / 2)] \
	[data->x + (data->width / 2)].color;
	zoom(&data->u, &data->v, data);
	zoom(&x1, &y1, data);
	map_move(&data->u, &data->v, data);
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

void	isometric(double *x, double *y, float *z, t_data *data)
{
	*x = ((*x - *y)) * cos(data->angle_x);
	*y = (((*x + *y)) * sin(data->angle_y)) - *z;
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
