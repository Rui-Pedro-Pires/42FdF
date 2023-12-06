/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:55:13 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/06 13:39:38 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_read_error(char *line)
{
	if (!line)
	{
		write(2, "Wrong format, please enter <./fdf ./path/file_map.fdf>\n", 55);
		exit(0);
	}
}

void	ft_open_error(int fd)
{
	if (fd < 0)
	{
		perror("Wrong file");
		exit(0);
	}
}
