/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:57:29 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/06 10:43:45 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	open_window(t_data *data)
{
	init_window(data);
	render_map(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, NoEventMask, &handle_close, data);
	mlx_hook(data->win_ptr, 4, 1L << 2, &handle_mouse_down, data);
	mlx_hook(data->win_ptr, 5, 1L << 3, &handle_mouse_up, data);
	mlx_hook(data->win_ptr, 6, 1L << 6, &handle_mouse_move, data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free (data->mlx_ptr);
}

int	init_window(t_data *data)
{
	data->zoom = 20;
	data->hor = (WIDTH - 200) / 2;
	data->hey = HEIGHT / 2;
	data->button = 0;
	data->angle_x = 0.567890;
	data->angle_y = -0.012300;
	data->angle_z = 0.743534;
	data->menu_color = 0x444444;
	data->color_save = 0;
	data->mlx_ptr = mlx_init();
	get_max_z(data);
	get_min_z(data);
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
