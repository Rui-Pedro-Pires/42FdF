/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:50:13 by ruiolive          #+#    #+#             */
/*   Updated: 2023/12/05 17:03:54 by ruiolive         ###   ########.fr       */
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
	data->map = malloc(sizeof(t_fdf *) * data->height);
	if (!data->map)
		return ;
	while (y < data->height)
	{
		data->map[y] = malloc(sizeof(t_fdf) * data->width);
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
			fill_matrix(data, x, y, splited[x]);
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

void	fill_matrix(t_data *data, int x, int y, char *splited)
{
	if (check_for_colors(splited))
	{
		data->map[y][x].z = ft_atoi(splited);
		data->map[y][x].color = atoi_base(splited);
	}
	else
	{
		data->map[y][x].z = ft_atoi(splited);
		data->map[y][x].color = 16777215;
	}
}

void	ft_write_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			printf("%d\n", data->map[y][x].color);
			x++;
		}
		printf("\n");
		y++;
	}
}

