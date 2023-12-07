/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:05:50 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/07 10:39:47 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	render_map(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH - 200, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, \
	&data->img.line_len, &data->img.endian);
	data->y = data->height / 2 * -1;
	if (data->height % 2 != 0 && data->width % 2 != 0)
		map_impar(data);
	else if (data->height % 2 == 0 && data->width % 2 == 0)
		map_par(data);
	else if (data->height % 2 != 0 && data->width % 2 == 0)
		map_misto1(data);
	else
		map_misto2(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->img.mlx_img, 200, 0);
	menu_render(data);
	return (0);
}

int	menu_render(t_data *data)
{
	render_strings1(data);
	render_strings2(data);
	menu_background_render(data);
	return (0);
}

int	menu_background_render(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < 200)
		{
			if (x < 5 || x > 194 || y < 5 || y > HEIGHT - 90)
				mlx_pixel_put(data->mlx_ptr, \
				data->win_ptr, x, y, data->menu_color);
			x++;
		}
		y++;
	}
	return (0);
}

void	render_strings1(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, \
	50, 0x999999, "MENU");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	100, 0xFFFFFF, "Press R to reset");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	140, 0xFFFFFF, "Press + to increase high");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	180, 0xFFFFFF, "Press - to decrease high");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	220, 0xFFFFFF, "Press Q/W to rotate X axis");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	260, 0xFFFFFF, "Press A/S to rotate Y axis");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	300, 0xFFFFFF, "Press Z/X to rotate Z axis");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	340, 0xFFFFFF, "Mouse L click to rotate X/Y");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	380, 0xFFFFFF, "Mouse Mid click to rotate Z");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	420, 0xFFFFFF, "Mouse R click to move");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	440, 0xFFFFFF, "the map position");
}

void	render_strings2(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	480, 0xFFFFFF, "Scroll down to zoom out");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	520, 0xFFFFFF, "Scroll up to zoom in");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	560, 0xFFFFFF, "Press F2/F3 to change color");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	600, 0xFFFFFF, "Press F1 to change color");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	620, 0xFFFFFF, "to default");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	660, 0xFFFFFF, "Press 1/2/3/4 to");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	680, 0xFFFFFF, "change perspective");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	720, 0xFFFFFF, "Press P to");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 25, \
	740, 0xFFFFFF, "change color dynamically");
}
