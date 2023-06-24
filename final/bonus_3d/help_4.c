/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:41:07 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/24 17:28:11 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	h_plane(t_vars *vars, t_var *v)
{
	vars->distance_wall = vars->plane_des_h;
	vars->plane_des_h = vars->plane_des_h * cos(v->angle * (M_PI / 180));
	vars->plane_height = (vars->size / vars->plane_des_h) * v->p_d;
	vars->xi = v->r;
	vars->yi = ((vars->height_window) / 2 - (vars->plane_height) / 2);
	vars->xf = v->r;
	vars->yf = (vars->height_window) / 2 + (vars->plane_height) / 2;
	if (sin(vars->deriction + v->angle * (M_PI / 180)) < 0)
	{
		v->offset = (int)((fmod(vars->plane_x_h, vars->size)
					/ vars->size) * vars->n_image.width);
		ber(vars, v->offset, &vars->n_image);
	}
	else
	{
		v->offset = (int)((1 - (fmod(vars->plane_x_h, vars->size) / vars->size))
				* vars->s_image.width);
		ber(vars, v->offset, &vars->s_image);
	}
}

void	help_simple_draw(t_vars *vars, t_var *v)
{
	vars->xi = v->r;
	vars->yf = ((vars->height_window) / 2 - (vars->plane_height) / 2);
	vars->xf = v->r;
	vars->yi = 0;
	ber_floor_ceil(vars, vars->color_ceil);
	vars->yi = (vars->height_window) / 2 + (vars->plane_height) / 2;
	vars->yf = vars->height_window;
	ber_floor_ceil(vars, vars->color_floor);
}

void	simple_draw(t_vars *vars, t_var *v)
{
	t_doors	doors;

	v->r = 0;
	v->p_d = ((vars->width_window) / 2) / tan(30 * (M_PI / 180));
	v->angle = -30;
	v->pas = 60.0 / vars->width_window;
	while (v->r < (vars->width_window))
	{
		doors.distance = ft_calloc(sizeof(double), (vars->len_v * vars->len_h));
		doors.distancesoff = ft_calloc(sizeof(double),
				(vars->len_v * vars->len_h));
		ft_step_h(vars, vars->deriction + v->angle * (M_PI / 180), &doors);
		ft_steps_v(vars, vars->deriction + v->angle * (M_PI / 180), &doors);
		if (vars->plane_des_h >= vars->plane_des_v)
			v_plane(vars, v);
		else
			h_plane(vars, v);
		help_simple_draw(vars, v);
		draw_wall(vars, v, &doors);
		v->angle += v->pas;
		v->r++;
	}
}

int	ft_draw(t_vars *vars)
{
	t_var	v;

	v.i = 0;
	create_image(vars);
	while (vars->store_map[v.i] != NULL)
	{
		v.j = 0;
		while (vars->store_map[v.i][v.j])
		{
			print_2d_map(vars, v.i, v.j);
			if (v.j == (int)vars->player_x / (vars->size)
				&& v.i == (int)vars->player_y / (vars->size))
			{
				print_player(vars);
				simple_draw(vars, &v);
			}
			v.j++;
		}
		v.i++;
	}
	put_destroy_image(vars);
	return (0);
}

void	help_move(t_vars *vars)
{
	if (vars->up == 1 || vars->f_up == 1)
	{
		if (check_pixel(vars, 0, cos(vars->deriction) * vars->speed) == 0)
			vars->player_x += cos(vars->deriction) * vars->speed;
		if (check_pixel(vars, sin(vars->deriction) * vars->speed, 0) == 0)
			vars->player_y += sin(vars->deriction) * vars->speed;
	}
	if ((vars->right == 1) && check_pixel(vars, sin(vars->deriction + (M_PI
					/ 2)) * vars->speed, cos(vars->deriction + (M_PI / 2))
			* vars->speed) == 0)
	{
		vars->player_x += cos(vars->deriction + (M_PI / 2)) * vars->speed;
		vars->player_y += sin(vars->deriction + (M_PI / 2)) * vars->speed;
	}
	if ((vars->left == 1) && check_pixel(vars, sin(vars->deriction - (M_PI / 2))
			* vars->speed, cos(vars->deriction - (M_PI / 2))
			* vars->speed) == 0)
	{
		vars->player_x += cos(vars->deriction - (M_PI / 2)) * vars->speed;
		vars->player_y += sin(vars->deriction - (M_PI / 2)) * vars->speed;
	}
}
