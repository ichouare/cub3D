/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:28:07 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/22 13:31:17 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(char const *p)
{
	size_t	size;

	size = 0;
	while (*(p + size))
		size++;
	return (size);
}

int	search(char *str, char n)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while ((str1[i] || str2[i]) && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

int	ft_strncmp( const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*str11 ;
	unsigned char	*str22 ;

	str11 = (unsigned char *)str1 ;
	str22 = (unsigned char *)str2 ;
	i = 0;
	if (n == 0)
		return (0);
	while ((*(str11 + i) || *(str22 + i))
		&& *(str11 + i) == *(str22 + i) && i < n - 1)
		i++;
	return (*(str11 + i) - *(str22 + i));
}

int	ft_strlen2d(char **s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}
