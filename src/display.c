/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:10:56 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/27 15:43:14 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	open_window(t_data *data)
{
	init_window(data);
	render_map(data);
	mlx_mouse_hook(data->win_ptr, &mouse_input, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, &handle_close, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free (data->mlx_ptr);
}

int	render_map(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
	&data->img.line_len, &data->img.endian);
	data->y = 0;
	while (data->y < (data->height))
	{
		data->x = 0;
		while (data->x < (data->width))
		{
			if (data->x < data->width - 1)
				bresenhaim(data, data->x + 1, data->y);
			if (data->y < data->height - 1)
				bresenhaim(data, data->x, data->y + 1);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,\
	 data->img.mlx_img, 0, 0);
	return (0);
}

int	render_map_2d(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
	&data->img.line_len, &data->img.endian);
	data->y = 0;
	while (data->y < data->height)
	{
		data->x = 0;
		while (data->x < data->width)
		{
			if (data->x < data->width - 1)
				bresenhaim_2d(data, data->x + 1, data->y);
			if (data->y < data->height - 1)
				bresenhaim_2d(data, data->x, data->y + 1);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,\
	 data->img.mlx_img, 0, 0);
	return (0);
}

int	init_window(t_data *data)
{
	data->zoom = 20;
	// while ((data->width * data->zoom) > (WIDTH / 1.5) && (data->height * data->zoom ) > (HEIGHT))
	// {
	// 	data->zoom /= 2;
	// }
	data->prespective = 1;
	data->hor = WIDTH / 2;
	data->hey = HEIGHT / 2 - data->height * 4;
	data->angle_x = 0.8;
	data->angle_y = 0.8;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FdF");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		exit (2);
	}
	return (1);
}
