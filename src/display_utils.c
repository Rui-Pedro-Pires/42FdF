/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:48:54 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/24 17:44:29 by ruiolive         ###   ########.fr       */
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
	*x += data->right;
	*y += data->left;
}

// void	increase_z(t_data *data)
// {
// 	t_list	*map;

// 	map = data->map;
// 	while (map)
// 	{
// 		if (map->z != 0)
// 			map->z++;
// 		map = map->next;
// 	}
// }

// void	decrease_z(t_data *data)
// {
// 	t_list	*map;

// 	map = data->map;
// 	while (map)
// 	{
// 		if (map->z != 0)
// 			map->z--;
// 		map = map->next;
// 	}
// }