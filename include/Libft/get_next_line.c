/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:53:52 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/17 12:38:06 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buffer;
	char		*line;
	int			read_lines;

	read_lines = 1;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!(ft_find_new_line(buffer)) && read_lines)
	{
		read_lines = read(fd, buffer, BUFFER_SIZE);
		if (read_lines < 0)
			return (ft_clean(&save, &buffer));
		buffer[read_lines] = '\0';
		save = ft_add_to_save(save, buffer);
	}
	line = ft_fill_line(save);
	save = ft_clean_save(save);
	free(buffer);
	return (line);
}

char	*ft_add_to_save(char *save, char *buffer)
{
	char	*temp;
	int		i;
	int		j;
	int		size;

	if (!buffer)
		return (NULL);
	if (!save)
		save = ft_calloc(1, sizeof(char));
	i = 0;
	j = 0;
	size = ft_strlen_get(save) + ft_strlen_get(buffer);
	temp = ft_calloc((size + 1), sizeof(char));
	while (save[i])
	{
		temp[i] = save[i];
		i++;
	}
	while (buffer[j])
		temp[i++] = buffer[j++];
	temp[i] = '\0';
	free(save);
	return (temp);
}

char	*ft_fill_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!*save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			break ;
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_clean_save(char *save)
{
	int			i;
	int			j;
	char		*new_save;

	i = 0;
	j = 0;
	if (!*save)
	{
		free(save);
		return (NULL);
	}
	while (save[i] && save[i] != '\n')
		i++;
	new_save = ft_calloc(ft_strlen_get(save) - i + 1, 1);
	while (save[i])
		new_save[j++] = save[++i];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}
