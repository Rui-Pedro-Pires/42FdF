/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transf_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:21:04 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/05 12:18:49 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	zoom(double *x, double *y, t_data *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	data->u *= data->zoom;
	data->v *= data->zoom;
}

void	map_move(double *x, double *y, t_data *data)
{
	*x += data->hor;
	*y += data->hey;
	data->u += data->hor;
	data->v += data->hey;
}
