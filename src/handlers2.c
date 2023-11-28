/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:42:20 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/28 16:07:06 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	increase_z(t_data *data)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if ((data->map[y][x] > 0.1 || data->map[y][x] < -1) 
			&& data->map[y][x] < HEIGHT / 5)
				data->map[y][x] += 1;
			x++;
		}
		y++;
	}
	return (0);
}

int	decrease_z(t_data *data)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if ((data->map[y][x] > 1 || data->map[y][x] < -1) 
			&& data->map[y][x] > (HEIGHT / 5 * -1))
				data->map[y][x] -= 1;
			x++;
		}
		y++;
	}
	return (0);
}

int	mouse_input(int	keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		if ((data->width * data->zoom) < WIDTH)
			data->zoom *= 1.5;
	}
	if (keycode == 5)
	{
		if (data->zoom > 3)
			data->zoom /= 1.5;
	}
	if (keycode == 1)
	{
		mlx_mouse_get_pos(data->mlx_ptr, data->win_ptr, &data->hor, &data->hey);
		data->hor -= 300;
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		render_map(data);
		return (0);
	}
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	render_map(data);
	return (0);
}