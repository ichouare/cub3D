/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:57:58 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/22 19:56:35 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	help_minimap_one(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 200)
		{
			my_mlx_pixel_put(&vars->minimap, i, j, 99541);
			j++;
		}
		i++;
	}
}

void	help_minimap_two(t_vars *vars, int i, int j)
{
	char	*buf;

	if ((i + (vars->player_y)) >= 0 && (i + (vars->player_y)) < vars->size
		* vars->len_v)
	{
		while (j < 100)
		{
			if ((j + vars->player_x) >= 0 && (j
					+ vars->player_x) < vars->size * vars->len_h)
			{
				buf = (vars->two_d_image.addr + (int)((int)(i
								+ vars->player_y)
							* vars->two_d_image.line_length) + (int)((int)(j
								+ vars->player_x)
							* (vars->two_d_image.bits_per_pixel / 8)));
				my_mlx_pixel_put(&vars->minimap, j + 100, i + 100,
					*(unsigned int *)buf);
			}
			j++;
		}
	}
}

void	minimap(t_vars *vars)
{
	int		i;
	int		j;

	i = -100;
	help_minimap_one(vars);
	while (i < 100)
	{
		j = -100;
		help_minimap_two(vars, i, j);
		i++;
	}
}

void	create_image(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->mlx_win);
	vars->main_image.img = mlx_new_image(vars->mlx, vars->width_window,
			vars->height_window);
	vars->main_image.addr = mlx_get_data_addr(vars->main_image.img,
			&vars->main_image.bits_per_pixel,
			&vars->main_image.line_length,
			&vars->main_image.endian);
	make_image(vars);
}

void	put_destroy_image(t_vars *vars)
{
	minimap(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->main_image.img, 0,
		0);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->main_image.img, 0,
		0);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->minimap.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->two_d_image.img);
	mlx_destroy_image(vars->mlx, vars->main_image.img);
}
