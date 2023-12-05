/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:26:16 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/05 15:12:52 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_mouse_move(int x, int y, t_data *data)
{
	if (data->button == 1)
	{
		data->hor += (x - data->prev_x);
		data->hey += (y - data->prev_y);
		data->prev_x = x;
		data->prev_y = y;
	}
	else if (data->button == 2)
	{
		data->angle_z -= (x - data->prev_x - (y - data->prev_y)) * 0.002;
		data->prev_x = x;
		data->prev_y = y;
	}
	else if (data->button == 3)
	{
		data->angle_x -= (y - data->prev_y) * 0.002;
		data->angle_y += (x - data->prev_x) * 0.002;
		data->prev_x = x;
		data->prev_y = y;
	}
	else
		return (0);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	render_map(data);
	return (0);
}

int	handle_mouse_down(int button, int x, int y, t_data *data)
{
	if (button == 1 || button == 2 || button == 3)
	{
		data->prev_x = x;
		data->prev_y = y;
		data->button = button;
	}
	else if (button == 4)
	{
		if (data->zoom < 150)
			data->zoom *= 1.5;
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		render_map(data);
	}
	else if (button == 5)
	{
		if (data->zoom > 3)
			data->zoom /= 1.5;
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		render_map(data);
	}
	return (0);
}

int	handle_mouse_up(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 1 || button == 2 || button == 3)
		data->button = 0;
	return (0);
}
