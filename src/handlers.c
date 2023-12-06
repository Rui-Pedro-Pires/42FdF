/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:15:55 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/06 10:24:37 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		handle_close(data);
	else if (keysym == XK_Right || keysym == XK_Left || \
	keysym == XK_Up || keysym == XK_Down || keysym == XK_r)
		move_handle(keysym, data);
	else if (keysym == XK_q || keysym == XK_w || keysym == XK_a \
	|| keysym == XK_s || keysym == XK_z || keysym == XK_x)
		angle_handle(keysym, data);
	else if (keysym == XK_1 || keysym == XK_2 || keysym == XK_3 \
	|| keysym == XK_4)
		projection_handle(keysym, data);
	else if (keysym == XK_KP_Add || keysym == XK_KP_Subtract)
		z_handle(keysym, data);
	else if (keysym == XK_F1 || keysym == XK_F2 || keysym == XK_F3)
		color_handler(keysym, data);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	render_map(data);
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free (data->mlx_ptr);
	ft_free_map(data);
	exit(1);
	return (0);
}

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
			if (data->map[y][x].z > 0.8 && data->map[y][x].z < 200)
				data->map[y][x].z *= 1.2;
			else if (data->map[y][x].z < -0.8 && data->map[y][x].z > -200)
				data->map[y][x].z /= 1.2;
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
			x++;
		}
		y++;
	}
	return (0);
}
