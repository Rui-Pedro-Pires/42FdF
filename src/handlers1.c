/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:15:55 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/28 16:01:01 by ruiolive         ###   ########.fr       */
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
	else if (keysym == XK_x || keysym == XK_y 
	|| keysym == XK_F1 || keysym == XK_F2 || keysym == XK_F3)
		angle_handle(keysym, data);
	else if (keysym == XK_KP_Add || keysym == XK_KP_Subtract)
		z_handle(keysym, data);
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
		data->hor = WIDTH / 2;
		data->hey = HEIGHT / 2;
		data->angle_x = 0.8;
		data->angle_y = 0.8;
	}
	return (0);
}

int	angle_handle(int keysym, t_data *data)
{
	if (keysym == XK_x)
		data->angle_x += 0.1;
	else if (keysym == XK_y)
		data->angle_y += 0.1;
	else if (keysym == XK_F1)
	{
		data->prespective = 1;
		data->angle_x =  0.8;
		data->angle_y = 0.8;
	}
	else if (keysym == XK_F2)
	{
		data->prespective = 1;
		data->angle_x = 0;
		data->angle_y = 0;
	}
	else if	(keysym == XK_F3)
		data->prespective = 2;
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
