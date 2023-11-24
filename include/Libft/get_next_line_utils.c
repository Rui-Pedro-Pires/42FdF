/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:54:02 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/17 12:34:19 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*s1;
	int		i;
	int		n;

	i = 0;
	n = nitems * size;
	s1 = malloc(nitems * size);
	if (!s1)
		return (NULL);
	while (n--)
		s1[i++] = '\0';
	return (s1);
}

int	ft_strlen_get(char *s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
		i++;
	return (i);
}

int	ft_find_new_line(char	*buffer)
{
	int	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_clean(char **save, char **buffer)
{
	free(*save);
	free(*buffer);
	*save = NULL;
	return (NULL);
}
