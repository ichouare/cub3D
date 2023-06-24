/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:42:31 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/24 17:24:58 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	red_cross(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(write(2, "END game\n", 10));
}

int	init_help_image(t_vars *vars)
{
	vars->n_image.img = mlx_xpm_file_to_image(vars->mlx, vars->image_nswe[0],
			&vars->n_image.width, &vars->n_image.height);
	vars->e_image.img = mlx_xpm_file_to_image(vars->mlx, vars->image_nswe[3],
			&vars->e_image.width, &vars->e_image.height);
	vars->w_image.img = mlx_xpm_file_to_image(vars->mlx, vars->image_nswe[2],
			&vars->w_image.width, &vars->w_image.height);
	vars->s_image.img = mlx_xpm_file_to_image(vars->mlx, vars->image_nswe[1],
			&vars->s_image.width, &vars->s_image.height);
	if (vars->image_nswe)
	{
		free2d(vars->image_nswe);
		free(vars->image_nswe);
	}
	if (!vars->n_image.img || !vars->e_image.img || !vars->w_image.img
		|| !vars->s_image.img)
	{
		write(2, "problen in mlx_xpm_file_to_image \n", 35);
		return (-1);
	}
	return (0);
}

int	init_image(t_vars *vars)
{
	if (init_help_image(vars) == -1)
		return (-1);
	vars->n_image.addr = mlx_get_data_addr(vars->n_image.img,
			&vars->n_image.bits_per_pixel, &vars->n_image.line_length,
			&vars->n_image.endian);
	vars->e_image.addr = mlx_get_data_addr(vars->e_image.img,
			&vars->e_image.bits_per_pixel, &vars->e_image.line_length,
			&vars->e_image.endian);
	vars->w_image.addr = mlx_get_data_addr(vars->w_image.img,
			&vars->w_image.bits_per_pixel, &vars->w_image.line_length,
			&vars->w_image.endian);
	vars->s_image.addr = mlx_get_data_addr(vars->s_image.img,
			&vars->s_image.bits_per_pixel, &vars->s_image.line_length,
			&vars->s_image.endian);
	if (!vars->n_image.addr || !vars->e_image.addr || !vars->w_image.addr
		|| !vars->s_image.addr)
	{
		write(2, "error :mlx_get_data_addr\n", 26);
		return (-1);
	}
	return (0);
}

void	init_var(t_vars *vars)
{
	vars->image_nswe = (char **)ft_calloc(sizeof(char *), 5);
	vars->map = 0;
	vars->store_map = NULL;
	vars->texture = NULL;
	vars->mlx = NULL;
	vars->mlx_win = NULL;
	vars->left = 0;
	vars->right = 0;
	vars->down = 0;
	vars->up = 0;
	vars->f_left = 0;
	vars->f_right = 0;
	vars->f_down = 0;
	vars->f_up = 0;
	vars->size = 10;
	vars->width_window = 1280;
	vars->height_window = 720;
	vars->speed = 1;
	vars->xi = 0;
	vars->xf = 0;
	vars->yf = 0;
	vars->yi = 0;
}

void	help_exit(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->store_map)
	{
		free2d(vars->store_map);
		free(vars->store_map);
	}
	if (vars->texture)
	{
		while (vars->texture[i])
		{
			free2d(vars->texture[i]);
			free(vars->texture[i]);
			i++;
		}
		free(vars->texture);
	}
	if (vars->image_nswe)
	{
		free2d(vars->image_nswe);
		free(vars->image_nswe);
	}
	exit(0);
}
