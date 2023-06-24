/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:39:52 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/21 14:39:58 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isalpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_catacter(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
			j++;
		i++;
	}
	return (j);
}

int	ft_lastindex(char *str, int find)
{
	int	i;

	i = ft_strlen(str);
	while (i != 0)
	{
		if (str[i] == find)
			return (i);
		i--;
	}
	return (-1);
}

void	check_table(int *table, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (table[i] == 3)
		{
			write(2, "error in map\n", 13);
			exit(0);
		}
		i++;
	}
}

void	iterate_width(int *table, char **map, int i, int len)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == '1')
			table[j] = 1;
		else if (search("0NSEW", map[i][j]) == 1 && table[j] == 0)
			table[j] = 3;
		else if (map[i][j] == ' ')
			table[j] = 0;
		j++;
	}
	while (j < len)
	{
		table[j] = 0;
		j++;
	}
}
