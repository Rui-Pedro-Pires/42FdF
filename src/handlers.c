/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:15:55 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/24 18:52:27 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_display(data->mlx_ptr);
		free (data->mlx_ptr);
		ft_free_map(data);
		exit(1);
	}
	else if (keysym == XK_KP_Add)
		data->zoom += 2;
	else if (keysym == XK_KP_Subtract)
		data->zoom -= 2;
	else if (keysym == XK_Right)
		data->right += 5;
	else if (keysym == XK_Left)
		data->right -= 5;
	else if (keysym == XK_Up)
		data->left -= 5;
	else if (keysym == XK_Down)
		data->left += 5;
	// else if (keysym == XK_z)
	// 	increase_z(data);
	// else if (keysym == XK_x)
	// 	decrease_z(data);
	else if (keysym == XK_o)
		data->angle += 0.2;
	else if (keysym == XK_p)
		data->angle -= 0.2;
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
	exit(2);
	return (0);
}
