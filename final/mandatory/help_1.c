/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:34:12 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/22 17:49:04 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file_name(char *map_name)
{
	int		len;
	char	*extension;
	int		i;

	extension = ".cub";
	i = 3;
	len = ft_strlen(map_name);
	while (0 <= len-- && i >= 0)
	{
		if (extension[i] != map_name[len])
		{
			write(2, "ERROR : your file exstension not valide\n", 41);
			exit(0);
		}
		i--;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(int *)dst = color;
}

int	check_pixel(t_vars *vars, double sin_value, double cos_value)
{
	double	i;
	double	j;

	i = vars->player_y + sin_value - 2;
	while (i < vars->player_y + sin_value + 2)
	{
		j = vars->player_x + cos_value - 2;
		while (j < vars->player_x + cos_value + 2)
		{
			if (vars->store_map[(int)(i / vars->size)]
					[(int)(j / vars->size)] == '1')
				return (-1);
			j += 1;
		}
		i += 1;
	}
	return (0);
}

void	help_key_hook(int key, t_vars *vars)
{
	if (key == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	if (key == 126)
		vars->f_up = 1;
	if (key == 124)
		vars->f_right = 1;
	if (key == 123)
		vars->f_left = 1;
	if (key == 125)
		vars->f_down = 1;
	if (key == 13)
		vars->up = 1;
}

int	key_hook(int key, t_vars *vars)
{
	help_key_hook(key, vars);
	if ((key == 2) && check_pixel(vars, sin(vars->deriction + (M_PI / 2))
			* vars->speed, cos(vars->deriction + (M_PI / 2))
			* vars->speed) == 0)
		vars->right = 1;
	if ((key == 0) && check_pixel(vars, sin(vars->deriction - (M_PI / 2))
			* vars->speed, cos(vars->deriction - (M_PI / 2))
			* vars->speed) == 0)
		vars->left = 1;
	if (((key == 1)) && check_pixel(vars, -sin(vars->deriction) * vars->speed,
			-cos(vars->deriction) * vars->speed) == 0)
		vars->down = 1;
	return (0);
}
