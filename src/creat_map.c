/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:50:13 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/28 15:46:00 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	map_size(char *file, t_data *data)
{
	int		fd;
	int		x;
	char	*line;
	char	**line1;

	x = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit (0);
	}
	line = get_next_line(fd);
	line1 = ft_split(line, ' ');
	while (line1[x++])
		data->width++;
	ft_free_splited(line1);
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	creat_map(char *file, t_data *data)
{
	int	y;

	y = 0;
	data->width = 0;
	data->height = 0;
	map_size(file, data);
	data->map = malloc(sizeof(int *) * data->height);
	if (!data->map)
		return ;
	while (y < data->height)
	{
		data->map[y] = malloc(sizeof(int) * data->width);
		if (!data->map)
			return ;
		y++;
	}
	fill_map(file, data);
}

void	fill_map(char *file, t_data *data)
{
	int		x;
	int		y;
	int		fd;
	char	*line;
	char	**splited;

	fd = open(file, O_RDONLY);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		splited = ft_split(line, ' ');
		x = 0;
		while (x < data->width)
		{
			data->map[y][x] = ft_atoi(splited[x]);
			x++;
		}
		ft_free_splited(splited);
		free(line);
		line = get_next_line(fd);
		y++;
	}
	line = NULL;
	close(fd);
}

// void	ft_write_map(t_data *data)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < data->height)
// 	{
// 		x = 0;
// 		while (x < data->width)
// 		{
// 			printf("%3d", data->map[y][x]);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// }
