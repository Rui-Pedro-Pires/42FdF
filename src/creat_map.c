/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:50:13 by ruiolive          #+#    #+#             */
/*   Updated: 2023/11/24 19:17:32 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	size_height(char *file, t_data *data)
{
	int	fd;
	char 	*line;
	
	data->height = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		data->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	size_width(char *file, t_data *data)
{
	int	fd;
	int	x;
	char 	*line;
	char	**line1;
	
	data->width = 0;
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
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	ft_free_splited(line1);
	free(line);
	close(fd);
	return (0);
}

void	creat_map(char *file, t_data *data)
{
	int	y;
	
	y = 0;
	size_height(file, data);
	size_width(file, data);
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
	int	x;
	int	y;
	int	fd;
	char	*line;
	char 	**splited;
	
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
			printf("%3d", data->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}
