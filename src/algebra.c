/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:12:18 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/24 19:09:33 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenhaim(t_data *data, float x1, float y1)
{
	float	x_step;
	float	y_step;
	int	max;
	float	x;
	float	y;
	float	z;
	float	z1;
	int	color;

	x = data->x;
	y = data->y;
	z = data->map[(int)y][(int)x];
	z1 = data->map[(int)y1][(int)x1];
	if (z > 0 || z1 > 0)
		color = 0;
	else
		color = 1;
	isometric(&x, &y, &z, data);
	isometric(&x1, &y1, &z1, data);
	zoom(&x, &y, data);
	zoom(&x1, &y1, data);
	map_move(&x, &y, data);
	map_move(&x1, &y1, data);
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(positive(x_step), positive(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data, x, y, color);
		x += x_step;
		y += y_step;
	}
}

void	isometric(float *x, float *y, float *z, t_data *data)
{
	*x = (*x - *y) * cos(data->angle);
	*y = ((*x + *y) * sin(data->angle)) - *z;
}

float	MAX(float x_step, float y_step)
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

int	my_mlx_pixel_put(t_data *data, float x, float y, int color)
{
	if (x < (WIDTH - 1) && x >= 0 && y < (HEIGHT - 1) && y >= 0)
		data->img.addr[(int)x * (data->img.bpp / 8) + ((int)y * data->img.line_len) + color] = 0xFF;
	return (0);
}