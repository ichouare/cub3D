/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:45:09 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/23 20:01:57 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	iterate_height(int *table, char **map, int i)
{
	int	j;

	j = 0;
	while (map[j])
	{
		if ((int)ft_strlen(map[j]) > i)
		{
			if (map[j][i] == '1')
				table[j] = 1;
			else if (search("0NSEW", map[j][i]) == 1 && table[j] == 0)
				table[j] = 3;
			else if (map[j][i] == ' ')
				table[j] = 0;
		}
		else
			table[j] = 0;
		j++;
	}
}

int	ft_lenchr(char *s)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (ft_strchr("01NESWP", s[i]) != NULL)
			len++;
		i++;
	}
	return (len);
}

int	max_len2d(char **map)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > len)
			len = ft_strlen(map[i]);
		i++;
	}
	return (len);
}

void	free2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}
