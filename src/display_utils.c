/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:21:04 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/27 18:36:52 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom(float *x, float *y, t_data *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
}

void	map_move(float *x, float *y, t_data *data)
{
	*x += data->hor;
	*y += data->hey;
}

int	build_img(t_data *data)
{
	char	*ptr;
	
	ptr = NULL;
	data->color = 0xFF;
	colors_change(data);
	if (data->u < (WIDTH - 1) && data->u >= 0 \
	&& data->v < (HEIGHT - 1) && data->v >= 0)
	{
		ptr = data->img.addr + (int)data->u * (data->img.bpp / 8) \
		+ ((int)data->v * data->img.line_len);
		*(unsigned int *)ptr = data->color;
	}
	return (0);
}

void	colors_change(t_data *data)
{
	if (data->z > 0 || data->z1 > 0)
		data->color = 0x00FF00;
	else if (data->z > 5 || data->z1 > 5)
		data->color = 0xFFFFFFFF;
	else if (data->z > 10 || data->z1 > 10)
		data->color = 0xFF00FF;
	else if (data->z > 15 || data->z1 > 15)
		data->color = 0x00;
}