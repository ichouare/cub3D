/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:34:42 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/23 19:12:50 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	putnb(char *arr, int n, int c)
{
	int				i;
	int				s;
	unsigned int	m;

	s = 0;
	i = c - 1;
	if (n < 0)
	{
		n *= -1;
		arr[0] = '-';
		s++;
	}
	if (n == 0)
		arr[i] = (n % 10) + '0';
	m = n;
	while (i >= s)
	{
		arr[i] = (m % 10) + '0';
		m = m / 10;
		i--;
	}
	arr[c] = '\0';
}

static int	number_of_number(int n)
{
	int				i;
	unsigned int	m;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		i++;
	m = n ;
	while (m != 0)
	{
		m = m / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		c;
	char	*arr;

	c = number_of_number(n);
	arr = malloc(sizeof(char) * c + 1);
	if (! arr)
		exit (0);
	putnb(arr, n, c);
	return (arr);
}
