/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_parcer_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:50:46 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/24 17:17:02 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parcer_one(t_vars *vs, char *map_name, t_var *v)
{
	v->tmp = NULL;
	v->arr = NULL;
	v->color = NULL;
	v->new_line = 0;
	v->i = 0;
	v->tmp = NULL;
	v->fd = open(map_name, O_RDONLY);
	v->fd1 = open(map_name, O_RDONLY);
	if (v->fd < 0 || v->fd1 < 0)
		exit(write(2, "ERROR : FILE MAP\n", 18));
	v->tmp = get_next_line(v->fd);
	while (v->tmp != NULL)
	{
		v->i++;
		free(v->tmp);
		v->tmp = get_next_line(v->fd);
	}
	close(v->fd);
	if (v->i < 6)
		exit((write(2, "ERROR : FILE MAP\n", 18)));
	vs->store_map = NULL;
	vs->store_map = ft_calloc(sizeof(char *), v->i);
	vs->texture = NULL;
	vs->texture = ft_calloc(sizeof(char **), 7);
}

int	parcer_two(t_vars *vs, t_var *v)
{
	while (v->i < 6)
	{
		if (ft_catacter(v->tmp) != 0)
		{
			v->color = ft_split(v->tmp, ' ');
			if (ft_strlen2d(v->color) != 2)
			{
				free(v->tmp);
				if (v->color)
				{
					free2d(v->color);
					free(v->color);
				}
				write(2, "ERROR: not valid texture\n", 26);
				return (-1);
			}
			vs->texture[v->i] = v->color;
			v->i++;
		}
		free(v->tmp);
		v->tmp = get_next_line(v->fd1);
	}
	return (0);
}

int	check_map_err(t_vars *vs, t_var *v)
{
	v->i = 0;
	vs->len_v = 0;
	vs->len_h = 0;
	if (check_01(vs->store_map) == -1)
		return (-1);
	v->i = 0;
	while (vs->store_map[v->i])
	{
		if (ft_strchr(vs->store_map[v->i], '1') == NULL)
			v->new_line = 1;
		else
			vs->len_v++;
		if (ft_lenchr(vs->store_map[v->i]) > vs->len_h)
			vs->len_h = ft_lenchr(vs->store_map[v->i]);
		if (ft_strlen(vs->store_map[v->i]) != 0 && v->new_line == 1)
			return (-1);
		v->i++;
	}
	check_map(vs->store_map);
	return (0);
}

int	parcer_three(t_vars *vs, t_var *v)
{
	while (ft_catacter(v->tmp) == 0)
	{
		free(v->tmp);
		v->tmp = get_next_line(v->fd1);
	}
	if (parcer_two(vs, v) == -1)
		return (-1);
	if (v->i != 6)
		return (-1);
	v->i = 0;
	v->check = 0;
	while (v->tmp != NULL)
	{
		if (ft_catacter(v->tmp) != 0)
			v->check = 1;
		if (v->check == 1)
		{
			vs->store_map[v->i] = ft_strdup(v->tmp);
			v->i++;
		}
		free(v->tmp);
		v->tmp = get_next_line(v->fd1);
	}
	return (0);
}

int	parcer_four(t_vars *vs, t_var *v)
{
	v->i = 0;
	v->j = 0;
	while (v->i < 6)
	{
		if (ft_strcmp(vs->texture[v->i][0], "NO") == 0
			|| ft_strcmp(vs->texture[v->i][0], "SO") == 0
			|| ft_strcmp(vs->texture[v->i][0], "WE") == 0
			|| ft_strcmp(vs->texture[v->i][0], "EA") == 0
			|| ft_strcmp(vs->texture[v->i][0], "F") == 0
			|| ft_strcmp(vs->texture[v->i][0], "C") == 0)
			v->j++;
		else
		{
			write(2, "vs->texture not available\n", 27);
			return (-1);
		}
		v->i++;
	}
	if (v->j != 6)
	{
		write(2, "vs->texture don't  respect the rules\n", 38);
		return (-1);
	}
	return (0);
}
