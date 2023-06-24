/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:38:12 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/24 16:23:23 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	help_step_h(t_vars *vars, t_var *v, t_doors *doors)
{
	doors->cnt = 0;
	while (
		vars->plane_y_h + v->offset >= 0 && vars->plane_y_h + v->offset
		< vars->len_v * vars->size && vars->plane_x_h / vars->size >= 0
		&& vars->plane_x_h < (int)ft_strlen(vars->store_map
			[(int)((vars->plane_y_h + v->offset) / vars->size)]) * vars->size
			&& vars->store_map[(int)((vars->plane_y_h + v->offset)
				/ vars->size)][(int)(vars->plane_x_h / vars->size)] != '1')
	{
		if (vars->store_map[(int)((vars->plane_y_h + v->offset)
				/ vars->size)][(int)(vars->plane_x_h) / vars->size] == 'P')
		{
			doors->distance[doors->cnt] = sqrt(pow(vars->plane_x_h
						- vars->player_x, 2)
					+ pow(vars->plane_y_h - vars->player_y, 2));
			doors->distancesoff[doors->cnt] = vars->plane_x_h;
			doors->cnt++;
		}
		vars->plane_x_h += v->stepsx;
		vars->plane_y_h += v->stepsy;
	}
	vars->plane_des_h = sqrt(pow(vars->plane_x_h - vars->player_x, 2)
			+ pow(vars->plane_y_h - vars->player_y, 2));
}

int	ft_step_h(t_vars *vars, double angle, t_doors *doors)
{
	t_var	v;

	v.stepsx = 0;
	v.stepsy = 0;
	v.dx = 0;
	v.dy = 0;
	v.offset = 0;
	v.dy = (int)(vars->player_y / vars->size) * vars->size;
	if (sin(angle) > 0)
		v.dy += vars->size;
	v.dx = (vars->player_x) + ((v.dy - (vars->player_y)) / tan(angle));
	vars->plane_x_h = v.dx;
	vars->plane_y_h = v.dy;
	v.stepsy = vars->size;
	if (sin(angle) < 0)
	{
		v.stepsy = -vars->size;
		v.offset = -1;
	}
	v.stepsx = v.stepsy / tan(angle);
	help_step_h(vars, &v, doors);
	return (0);
}

void	help_steps_v(t_vars *vars, t_var *v, t_doors *doors)
{
	while (vars->plane_y_v >= 0 && vars->plane_y_v < vars->len_v * vars->size
		&& vars->plane_x_v + v->offset >= 0
		&& vars->plane_x_v + v->offset < (int)ft_strlen(
			vars->store_map[(int)vars->plane_y_v / vars->size])
		* vars->size && vars->store_map[(int)vars->plane_y_v / vars->size]
		[(int)(vars->plane_x_v + v->offset) / vars->size] != '1')
	{
		if (vars->store_map[(int)((vars->plane_y_v)
				/ vars->size)][(int)(vars->plane_x_v
			+ v->offset) / vars->size] == 'P')
		{
				doors->distance[doors->cnt] = sqrt(pow(vars->plane_x_v
						- vars->player_x, 2)
					+ pow(vars->plane_y_v - vars->player_y, 2));
					doors->distancesoff[doors->cnt] = vars->plane_y_v;
					doors->cnt++;
		}
		vars->plane_x_v += v->stepsx;
		vars->plane_y_v += v->stepsy;
	}
	vars->plane_des_v = sqrt(pow(vars->plane_x_v - vars->player_x, 2)
			+ pow(vars->plane_y_v - vars->player_y, 2));
}

int	ft_steps_v(t_vars *vars, double angle, t_doors *doors)
{
	t_var	v;

	v.stepsx = 0;
	v.stepsy = 0;
	v.dx = 0;
	v.dy = 0;
	v.offset = 0;
	v.dx = (floor)(vars->player_x / vars->size) * vars->size;
	if (cos(angle) > 0)
		v.dx += vars->size;
	v.dy = tan(angle) * (v.dx - vars->player_x) + vars->player_y;
	vars->plane_x_v = v.dx;
	vars->plane_y_v = v.dy;
	v.stepsx += vars->size;
	if (cos(angle) < 0)
	{
		v.stepsx *= -1;
		v.offset = -1;
	}
	v.stepsy = v.stepsx * tan(angle);
	help_steps_v(vars, &v, doors);
	return (0);
}

void	v_plane(t_vars *vars, t_var *v)
{
	vars->distance_wall = vars->plane_des_v;
	vars->plane_des_v = vars->plane_des_v * cos(v->angle * (M_PI / 180));
	vars->plane_height = ((vars->size) / vars->plane_des_v)
		* v->p_d;
	vars->xi = v->r;
	vars->yi = ((vars->height_window) / 2 - (vars->plane_height) / 2);
	vars->xf = v->r;
	vars->yf = (vars->height_window) / 2
		+ (vars->plane_height) / 2;
	if (cos(vars->deriction + v->angle * (M_PI / 180)) < 0)
	{
		v->offset = (int)((1 - (fmod(vars->plane_y_v, vars->size) / vars->size))
				* vars->w_image.width);
		ber(vars, v->offset, &vars->w_image);
	}
	else
	{
		v->offset = (int)(((fmod(vars->plane_y_v, vars->size))
					/ vars->size) * vars->e_image.width);
		ber(vars, v->offset, &vars->e_image);
	}
}
