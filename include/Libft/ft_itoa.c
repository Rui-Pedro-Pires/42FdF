/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive <ruiolive@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:46:38 by ruiolive          #+#    #+#             */
/*   Updated: 2023/10/09 15:54:07 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_num(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static int	ft_power(long nb, int power)
{
	if (power >= 1)
		return (nb * ft_power(nb, (power - 1)));
	else if (power < 0)
		return (0);
	else
		return (1);
}

static void	ft_putnbr(long n, char *s1)
{
	int	i;
	int	x;
	int	j;

	x = ft_count_num(n) - 1;
	i = 0;
	j = ft_count_num(n);
	while (i < j)
	{
		s1[i] = n / ft_power(10, x) + '0';
		n %= ft_power(10, x);
		x--;
		i++;
	}
	s1[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	*s1;
	int		i;
	long	num;

	num = n;
	i = 0;
	if (num < 0)
	{
		num *= -1;
		s1 = malloc(sizeof(char) * ft_count_num(num) + 2);
		if (s1 == NULL)
			return (NULL);
		s1[i] = '-';
		i++;
		ft_putnbr(num, s1 + i);
	}
	else
	{
		s1 = malloc(sizeof(char) * ft_count_num(num) + 1);
		if (s1 == NULL)
			return (NULL);
		ft_putnbr(num, s1);
	}
	return (s1);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(2147483647));
// }
