/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:55:37 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/22 19:56:27 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_image(t_vars *vars)
{
	vars->two_d_image.img = mlx_new_image(vars->mlx, vars->size * vars->len_h,
			vars->size * vars->len_v);
	vars->two_d_image.addr = mlx_get_data_addr(vars->two_d_image.img,
			&vars->two_d_image.bits_per_pixel,
			&vars->two_d_image.line_length,
			&vars->two_d_image.endian);
	vars->minimap.img = mlx_new_image(vars->mlx, 200, 200);
	vars->minimap.addr = mlx_get_data_addr(vars->minimap.img,
			&vars->minimap.bits_per_pixel,
			&vars->minimap.line_length,
			&vars->minimap.endian);
}

void	print_2d_map(t_vars *vars, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (vars->store_map[i][j] == '1')
	{
		while (x < vars->size)
		{
			y = 0;
			while (y < vars->size)
			{
				my_mlx_pixel_put(&vars->two_d_image, j * vars->size + y, i
					* vars->size + x, 16711680);
				y++;
			}
			x++;
		}
	}
}

void	print_player(t_vars *vars)
{
	t_var	v;

	v.i = 0;
	v.x = -2;
	while (v.x < 2)
	{
		v.y = -2;
		while (v.y < 2)
		{
			my_mlx_pixel_put(&vars->two_d_image, (vars->player_x / (vars->size))
				* vars->size + v.y, (vars->player_y / (vars->size))
				* vars->size + v.x, 978464);
			v.y++;
		}
		while (v.i < 10)
		{
			my_mlx_pixel_put(&vars->two_d_image, (vars->player_x / (vars->size))
				* vars->size + v.i * cos(vars->deriction), (vars->player_y
					/ (vars->size)) * vars->size + v.i * sin(vars->deriction),
				978464);
			v.i++;
		}
		v.x++;
	}
}
