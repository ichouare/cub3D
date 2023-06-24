/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:30:36 by ichouare          #+#    #+#             */
/*   Updated: 2023/06/24 16:21:56 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_vars *vars, t_var *v, t_doors *doors)
{
	while (doors->cnt >= 0)
	{
		if (doors->distance[doors->cnt] < vars->distance_wall)
			v_doors(vars, v, doors);
		doors->cnt--;
	}
	free(doors->distance);
	free(doors->distancesoff);
}

void	v_doors(t_vars *vars, t_var *v, t_doors *doors)
{
	vars->plane_des_v = doors->distance[doors->cnt]
		* cos(v->angle * (M_PI / 180));
	vars->plane_height = ((vars->size) / vars->plane_des_v)
		* v->p_d;
	vars->xi = v->r;
	vars->yi = ((vars->height_window) / 2 - (vars->plane_height) / 2);
	vars->xf = v->r;
	vars->yf = (vars->height_window) / 2
		+ (vars->plane_height) / 2;
	if (vars->plane_des_v >= 3 && vars->plane_des_v <= 10)
	{
		v->offset = (int)(((fmod(doors->distancesoff[doors->cnt],
							vars->size) / (double)vars->size))
				* vars->door_open.width);
		draw_door(vars, v->offset, &vars->door_open);
	}
	else if (vars->plane_des_v > 10)
	{
		v->offset = (int)(((fmod(doors->distancesoff[doors->cnt],
							vars->size) / vars->size))
				* vars->door_close.width);
		draw_door(vars, v->offset, &vars->door_close);
	}
}

void	help_draw_door(t_vars *vars, int offset_x, t_data *image, t_var *v)
{
	while (v->i <= v->s)
	{
		v->d = NULL;
		if (v->y <= 0 || v->y >= vars->height_window)
			v->y = 0;
		v->offset_y = fabs((v->y - vars->yi)) * ((double)image->height
				/ (vars->yf - vars->yi));
		v->d = (image->addr + (v->offset_y * image->line_length) + (offset_x
					* (int)(image->bits_per_pixel / 8)));
		if (*(unsigned int *)(v->d) != 0)
			my_mlx_pixel_put(&vars->main_image, (int)v->x,
				(int)v->y, *(int *)v->d);
		v->x += v->xinc;
		v->y += v->yinc;
		v->i++;
	}
}

void	draw_door(t_vars *vars, int offset_x, t_data *image)
{
	t_var	v;

	v.s = 0;
	v.i = 1;
	v.x = vars->xi;
	v.y = vars->yi;
	v.dy = vars->yf - vars->yi;
	v.dx = vars->xf - vars->xi;
	if (abs((int)v.dx) > abs((int)v.dy))
		v.s = abs((int)v.dx);
	else
		v.s = abs((int)v.dy);
	v.xinc = v.dx / v.s;
	v.yinc = v.dy / v.s;
	help_draw_door(vars, offset_x, image, &v);
}

int	move(t_vars *vars)
{
	if (vars->f_right == 1)
		vars->deriction += 0.08;
	if (vars->f_left == 1)
		vars->deriction -= 0.08;
	help_move(vars);
	if (vars->down == 1 || vars->f_down == 1)
	{
		if (check_pixel(vars, 0, -cos(vars->deriction) * vars->speed) == 0)
			vars->player_x -= cos(vars->deriction) * vars->speed;
		if (check_pixel(vars, -sin(vars->deriction) * vars->speed, 0) == 0)
			vars->player_y -= sin(vars->deriction) * vars->speed;
	}
	ft_draw(vars);
	sprite_move(vars);
	return (0);
}
