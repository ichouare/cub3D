/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:36:04 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/24 17:18:26 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_color(t_vars *vs, t_var *v)
{
	v->i = 0;
	while (v->i < 6)
	{
		if (ft_strcmp(vs->texture[v->i][0], "NO") == 0)
			vs->image_nswe[0] = ft_substr(vs->texture[v->i][1], 0,
					ft_strlen(vs->texture[v->i][1]));
		if (ft_strcmp(vs->texture[v->i][0], "SO") == 0)
			vs->image_nswe[1] = ft_substr(vs->texture[v->i][1], 0,
					ft_strlen(vs->texture[v->i][1]));
		if (ft_strcmp(vs->texture[v->i][0], "WE") == 0)
			vs->image_nswe[2] = ft_substr(vs->texture[v->i][1], 0,
					ft_strlen(vs->texture[v->i][1]));
		if (ft_strcmp(vs->texture[v->i][0], "EA") == 0)
			vs->image_nswe[3] = ft_substr(vs->texture[v->i][1], 0,
					ft_strlen(vs->texture[v->i][1]));
		if (get_floor_c(vs, v) == -1 || get_ceil_c(vs, v) == -1)
			return (-1);
		v->i++;
	}
	return (0);
}

int	check_dup_texture(t_vars *vs, t_var *v)
{
	v->i = 0;
	v->k = 0;
	while (vs->texture[v->i])
	{
		v->k = v->i + 1;
		while (vs->texture[v->k])
		{
			if (ft_strcmp(vs->texture[v->k][0], vs->texture[v->i][0]) == 0)
			{
				write(2, "vs->texture duplicated\n", 24);
				return (-1);
			}
			v->k++;
		}
		v->i++;
	}
	return (0);
}

int	check_color_err(t_var *v)
{
	while (v->color[v->j] != NULL)
	{
		if (ft_isalpha(v->color[v->j]) == -1 || ft_atoi(v->color[v->j]) < 0
			|| ft_atoi(v->color[v->j]) > 255)
		{
			if (v->color)
			{
				free2d(v->color);
				free(v->color);
			}
			write(2, "color not acceptable\n", 22);
			return (-1);
		}
		v->j++;
	}
	return (0);
}

int	check_texture_color(t_vars *vs, t_var *v)
{
	v->i = 0;
	while (v->i < 6)
	{
		if (ft_strcmp(vs->texture[v->i][0], "F") == 0
			|| ft_strcmp(vs->texture[v->i][0], "C") == 0)
		{
			v->tmp = ft_substr(vs->texture[v->i][1], 0,
					ft_strlen(vs->texture[v->i][1]));
			if (v->tmp == NULL)
				return (-1);
			v->color = ft_split(v->tmp, ',');
			free(v->tmp);
			v->j = 0;
			if (check_color_err(v) == -1)
				return (-1);
			if (v->color)
			{
				free2d(v->color);
				free(v->color);
			}
		}
		v->i++;
	}
	return (0);
}

int	parcer_map(t_vars *vs, char *map_name)
{
	t_var	v;

	parcer_one(vs, map_name, &v);
	v.i = 0;
	v.tmp = get_next_line(v.fd1);
	while (v.tmp != NULL)
	{
		if (parcer_three(vs, &v) == -1)
			return (0);
	}
	if (parcer_four(vs, &v) == -1)
		return (0);
	if (check_dup_texture(vs, &v) == -1)
		return (0);
	if (check_texture_color(vs, &v) == -1)
		return (0);
	if (get_texture_color(vs, &v) == -1)
		return (0);
	if (check_file_ex(vs) == -1)
		return (0);
	if (check_map_err(vs, &v) == -1)
		return (0);
	return (1);
}
