/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_parcer_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:44:59 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/23 20:00:50 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_top(char **map)
{
	int	*table_top;
	int	i;

	i = 0;
	table_top = ft_calloc(sizeof(int), max_len2d(map) + 1);
	while (map[i])
	{
		iterate_width(table_top, map, i, max_len2d(map));
		check_table(table_top, max_len2d(map));
		i++;
	}
	i = ft_strlen2d(map) - 1;
	ft_bzero(table_top, max_len2d(map));
	while (i >= 0)
	{
		iterate_width(table_top, map, i, max_len2d(map));
		check_table(table_top, max_len2d(map));
		i--;
	}
	free(table_top);
}

void	check_map(char **map)
{
	int	*table_left;
	int	i;

	check_top(map);
	table_left = ft_calloc(sizeof(int), ft_strlen2d(map) + 1);
	i = 0;
	while (i < max_len2d(map))
	{
		iterate_height(table_left, map, i);
		check_table(table_left, ft_strlen2d(map));
		i++;
	}
	ft_bzero(table_left, ft_strlen2d(map));
	i = max_len2d(map) - 1;
	while (i >= 0)
	{
		iterate_height(table_left, map, i);
		check_table(table_left, ft_strlen2d(map));
		i--;
	}
	free(table_left);
}

void	help_check_01(char **map, t_var *v)
{
	while (map[v->i])
	{
		v->j = 0;
		while (map[v->i][v->j])
		{
			if (map[v->i][v->j] == '0')
				v->number_of_zero++;
			else if (map[v->i][v->j] == '1')
				v->number_of_one++;
			else if (map[v->i][v->j] == 'N' ||
					map[v->i][v->j] == 'S' || map[v->i][v->j] == 'E'
					|| map[v->i][v->j] == 'W')
				v->len_p++;
			else if (ft_strchr(" 01NESWP\n", map[v->i][v->j]) == NULL)
				v->not_val++;
			v->j++;
		}
		v->i++;
	}
}

int	check_01(char **map)
{
	t_var	v;

	v.len_p = 0;
	v.number_of_one = 0;
	v.number_of_zero = 0;
	v.not_val = 0;
	v.i = 0;
	help_check_01(map, &v);
	if (v.number_of_zero < 1 || v.number_of_one < 1
		|| v.len_p != 1 || v.not_val != 0)
	{
		write(2, "ERROE : map not valide\n", 23);
		return (-1);
	}
	return (0);
}

int	is_print(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] > 32 && s[i] < 127)
			return (1);
		i++;
	}
	return (0);
}
