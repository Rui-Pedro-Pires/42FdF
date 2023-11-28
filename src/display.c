/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:10:56 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/28 17:07:48 by ruiolive         ###   ########.fr       */
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
	data->y = data->height / 2 * -1;
	if (data->height % 2 != 0 && data->prespective == 1)
		map_impar(data);
	else if (data->height % 2 == 0 && data->prespective == 1)
		map_par(data);
	else if (data->height % 2 != 0 && data->prespective == 2)
		map_impar_2d(data);
	else if (data->height % 2 == 0 && data->prespective == 2)
		map_par_2d(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,\
	 data->img.mlx_img, 0, 0);
	menu_render(data);
	return (0);
}

int	init_window(t_data *data)
{
	data->zoom = 20;
	data->prespective = 1;
	data->hor = WIDTH / 2;
	data->hey = HEIGHT / 2;
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

int	menu_render(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 20, 0xFFFFFF, "Press R to reset");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 40, 0xFFFFFF, "Press + to increase high");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 60, 0xFFFFFF, "Press - to decrease high");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 80, 0xFFFFFF, "Press X to rotate in x");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 100, 0xFFFFFF, "Press Y to rotate in y");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 120, 0xFFFFFF, "Mouse left click to change the map position");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 140, 0xFFFFFF, "Scroll Up to zoom out");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, 160, 0xFFFFFF, "Scroll down to zoom in");
	return (0);
}
