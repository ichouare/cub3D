/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:36:13 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/24 14:37:09 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ber_floor_ceil(t_vars *vars, int color)
{
	t_var	v;

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
	while (v.i <= v.s)
	{
		if (v.y < 0 || v.y >= vars->height_window)
			v.y = 0;
		my_mlx_pixel_put(&vars->main_image, (int)v.x, (int)v.y, color);
		v.x += v.xinc;
		v.y += v.yinc;
		v.i++;
	}
}

void	help_ber(t_vars *vars, int offset_x, t_data *image, t_var *v)
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
		my_mlx_pixel_put(&vars->main_image, (int)v->x, (int)v->y, *(int *)v->d);
		v->x += v->xinc;
		v->y += v->yinc;
		v->i++;
	}
}

void	ber(t_vars *vars, int offset_x, t_data *image)
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
	help_ber(vars, offset_x, image, &v);
}

int	kk(int key, t_vars *vars)
{
	if (key == 13)
		vars->up = 0;
	else if (key == 16)
		vars->scop = 0;
	else if (key == 2)
		vars->right = 0;
	else if (key == 0)
		vars->left = 0;
	else if (key == 1)
		vars->down = 0;
	else if (key == 126)
		vars->f_up = 0;
	else if (key == 124)
		vars->f_right = 0;
	else if (key == 123)
		vars->f_left = 0;
	else if (key == 125)
		vars->f_down = 0;
	else if (key == 3)
		vars->fire = 0;
	return (0);
}
