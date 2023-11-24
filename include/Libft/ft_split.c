/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:14:01 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/09 12:21:49 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static size_t	ft_strlen_c(const char *s1, char c)
{
	size_t	size;

	size = 0;
	while (*s1 != c && *s1)
	{
		size++;
		s1++;
	}
	return (size);
}

static void	ft_fill(char **split_str, char const *s, char c)
{
	int		i;
	size_t	size;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		size = ft_strlen_c(s, c);
		if (*s)
		{
			split_str[i] = ft_substr(s, 0, size);
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	split_str[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**split_str;
	int		count;

	count = ft_count_words(s, c);
	if (!s)
		return (NULL);
	split_str = malloc(sizeof(char *) * (count + 1));
	if (!split_str)
		return (NULL);
	ft_fill(split_str, s, c);
	return (split_str);
}

// int	main(void)
// {
// 	char **string;
// 	int	i;

// 	i = 0;
// 	string = ft_split("iabsihxbqiwbvec    e  gato     ff ", ' ');
// 	while (string[i])
// 	{
// 		printf("%s\n", string[i]);
// 		i++;
// 	}
// }