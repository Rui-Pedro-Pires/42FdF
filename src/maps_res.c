/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:52:12 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/05 10:36:14 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	map_par(t_data *data)
{
	while (data->y < (data->height / 2))
	{
		data->x = data->width / 2 * -1;
		while (data->x < (data->width / 2))
		{
			if (data->x < (data->width / 2) - 1)
				bresenham(data, data->x + 1, data->y);
			if (data->y < (data->height / 2) - 1)
				bresenham(data, data->x, data->y + 1);
			data->x++;
		}
		data->y++;
	}
}

void	map_impar(t_data *data)
{
	while (data->y <= (data->height / 2))
	{
		data->x = data->width / 2 * -1;
		while (data->x <= (data->width / 2))
		{
			if (data->x < (data->width / 2))
				bresenham(data, data->x + 1, data->y);
			if (data->y < (data->height / 2))
				bresenham(data, data->x, data->y + 1);
			data->x++;
		}
		data->y++;
	}
}

void	map_misto1(t_data *data)
{
	if (data->height % 2 != 0)
	{
		while (data->y <= (data->height / 2))
		{
			data->x = data->width / 2 * -1;
			while (data->x < (data->width / 2))
			{
				if (data->x < (data->width / 2) - 1)
					bresenham(data, data->x + 1, data->y);
				if (data->y < (data->height / 2))
					bresenham(data, data->x, data->y + 1);
				data->x++;
			}
			data->y++;
		}
	}
}

void	map_misto2(t_data *data)
{
	if (data->width % 2 != 0)
	{
		while (data->y < (data->height / 2))
		{
			data->x = data->width / 2 * -1;
			while (data->x <= (data->width / 2))
			{
				if (data->x < (data->width / 2))
					bresenham(data, data->x + 1, data->y);
				if (data->y < (data->height / 2) - 1)
					bresenham(data, data->x, data->y + 1);
				data->x++;
			}
			data->y++;
		}
	}
}
