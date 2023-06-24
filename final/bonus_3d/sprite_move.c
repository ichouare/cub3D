/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:52:17 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/24 00:55:08 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	help_move_sprite(t_vars *vars)
{
	while (vars->n < 9)
	{
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->iam[vars->n], -320, -180);
		vars->n++;
	}
	if (vars->n == 9)
	{
		vars->position += 1;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->iam[8],
			-320, -180 + vars->position);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->iam[9
			+ abs(vars->position) % 2], vars->width_window / 2 - 40,
			vars->height_window / 2 + vars->position);
		if (vars->position == 10)
			vars->position = -10;
	}
}

void	sprite_move(t_vars *vars)
{
	if (vars->fire == 1)
		help_move_sprite(vars);
	else if (vars->scop == 1)
	{
		while (vars->n < 9)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win,
				vars->iam[vars->n], -320, -180);
			vars->n++;
		}
		if (vars->n == 9)
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->iam[8],
				-320, -180);
	}
	else
	{
		vars->position = -10;
		vars->n = 0;
		if (vars->move_p > 4)
			vars->move_p = 0;
		mlx_put_image_to_window(vars->mlx, vars->mlx_win,
			vars->iam[vars->move_p], -200, -20);
	}
}
