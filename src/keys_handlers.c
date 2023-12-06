/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:27:10 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/06 14:11:48 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	move_handle(int keysym, t_data *data)
{
	if (keysym == XK_Right)
		data->hor += 5;
	else if (keysym == XK_Left)
		data->hor -= 5;
	else if (keysym == XK_Up)
		data->hey -= 5;
	else if (keysym == XK_Down)
		data->hey += 5;
	else if (keysym == XK_r)
	{
		data->zoom = 20;
		data->hor = (WIDTH - 200) / 2;
		data->hey = HEIGHT / 2;
		data->angle_x = 0.567890;
		data->angle_y = -0.012300;
		data->angle_z = 0.743534;
	}
	return (0);
}

int	angle_handle(int keysym, t_data *data)
{
	if (keysym == XK_q)
		data->angle_x += 0.05;
	else if (keysym == XK_w)
		data->angle_x -= 0.05;
	else if (keysym == XK_a)
		data->angle_y += 0.05;
	else if (keysym == XK_s)
		data->angle_y -= 0.05;
	else if (keysym == XK_z)
		data->angle_z += 0.05;
	else if (keysym == XK_x)
		data->angle_z -= 0.05;
	return (0);
}

int	z_handle(int keysym, t_data *data)
{
	if (keysym == XK_KP_Add)
		increase_z(data);
	else if (keysym == XK_KP_Subtract)
		decrease_z(data);
	return (0);
}

int	projection_handle(int keysym, t_data *data)
{
	if (keysym == XK_1)
	{
		data->angle_x = 0.567890;
		data->angle_y = -0.012300;
		data->angle_z = 0.743534;
	}
	else if (keysym == XK_2)
	{
		data->angle_x = 0.067890;
		data->angle_y = 0;
		data->angle_z = 0;
	}
	else if (keysym == XK_3)
	{
		data->angle_x = 0;
		data->angle_y = 0;
		data->angle_z = 0;
	}
	else if (keysym == XK_4)
	{
		data->angle_x = 7.853906;
		data->angle_y = 0;
		data->angle_z = 0;
	}
	return (0);
}

int	color_handler(int keysym, t_data *data)
{
	if (keysym == XK_F1)
		data->color_save = 1;
	else if (keysym == XK_F2)
		data->color_save = 2;
	else if (keysym == XK_F3)
		data->color_save = 3;
	else if (keysym == XK_p)
		data->add_color += 1;
	return (0);
}
