/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:20:08 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/24 19:26:32 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc == 2)
	{
		creat_map(argv[1], &data);
		//ft_write_map(&data);
		open_window(&data);
	}
	exit (0);
}
