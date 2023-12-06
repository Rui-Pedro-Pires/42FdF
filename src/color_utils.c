/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:24:47 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/06 11:46:33 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_max_z(t_data *data)
{
	int	x;
	int	y;
	int	z;

	y = 0;
	z = -500;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x].z > z)
				z = data->map[y][x].z;
			x++;
		}
		y++;
	}
	data->max_z = z;
}

void	get_min_z(t_data *data)
{
	int	x;
	int	y;
	int	z;

	y = 0;
	z = 1000;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->map[y][x].z < z)
				z = data->map[y][x].z;
			x++;
		}
		y++;
	}
	data->min_z = z;
}
