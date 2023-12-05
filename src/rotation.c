/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:42:07 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/04 14:46:19 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotation(t_data *data, double *x1, double *y1)
{
	rotate_y_axis(data, &data->u, &data->z);
	rotate_y_axis(data, x1, &data->z1);
	rotate_z_axis(data, &data->u, &data->v);
	rotate_z_axis(data, x1, y1);
	rotate_x_axis(data, &data->v, &data->z);
	rotate_x_axis(data, y1, &data->z1);
}

void	rotate_x_axis(t_data *data, double *y, float *z)
{
	double	save_y;

	save_y = *y;
	*y = save_y * cos(data->angle_x) - *z * sin(data->angle_x);
	*z = save_y * sin(data->angle_x) + *z * cos(data->angle_x);
}

void	rotate_y_axis(t_data *data, double *x, float *z)
{
	double	save_x;

	save_x = *x;
	*x = save_x * cos(data->angle_y) + *z * sin(data->angle_y);
	*z = *z * cos(data->angle_y) - save_x * sin(data->angle_y);
}

void	rotate_z_axis(t_data *data, double *x, double *y)
{
	double	save_x;
	double	save_y;

	save_x = *x;
	save_y = *y;
	*x = (save_x * cos(data->angle_z) - save_y * sin(data->angle_z));
	*y = (save_x * sin(data->angle_z) + save_y * cos(data->angle_z));
}
