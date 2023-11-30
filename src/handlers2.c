/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:42:20 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/30 17:12:36 by ruiolive         ###   ########.fr       */
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
			if (data->map[y][x].z > 2.)
				data->map[y][x].z *= 1.2;
			else if (data->map[y][x].z < -2.)
				data->map[y][x].z /= 1.2;
			// else if (data->map[y][x].z < HEIGHT / 10 && data->map[y][x].z != 0)
			// 	data->map[y][x].z *= 1.5;
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
			if (data->map[y][x].z > 2.5)
				data->map[y][x].z /= 1.2;
			else if (data->map[y][x].z < -2.5)
				data->map[y][x].z *= 1.2;
			// else if (data->map[y][x].z < 2);
				
			
			// else if (data->map[y][x].z > (HEIGHT / 10 * -1) \
			// && data->map[y][x].z != 0)
			// 	data->map[y][x].z /= 1.5;
			x++;
		}
		y++;
	}
	return (0);
}

int	mouse_input(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		if (data->zoom < WIDTH / 2)
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
		data->hor -= 200;
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		render_map(data);
		return (0);
	}
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	render_map(data);
	return (0);
}
