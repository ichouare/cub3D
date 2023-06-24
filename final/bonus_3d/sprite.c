/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:43:07 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/24 14:25:38 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_aim_image(void)
{
	int	fd[13];
	int	i;

	i = 0;
	fd[0] = open("aim/AnyConv.com__hk53_aim.1.xpm", O_RDONLY);
	fd[1] = open("aim/AnyConv.com__hk53_aim.2.xpm", O_RDONLY);
	fd[2] = open("aim/AnyConv.com__hk53_aim.3.xpm", O_RDONLY);
	fd[3] = open("aim/AnyConv.com__hk53_aim.4.xpm", O_RDONLY);
	fd[4] = open("aim/AnyConv.com__hk53_aim.5.xpm", O_RDONLY);
	fd[5] = open("aim/AnyConv.com__hk53_aim.6.xpm", O_RDONLY);
	fd[6] = open("aim/AnyConv.com__hk53_aim.7.xpm", O_RDONLY);
	fd[7] = open("aim/AnyConv.com__hk53_aim.9.xpm", O_RDONLY);
	fd[8] = open("aim/AnyConv.com__hk53_aim.11.xpm", O_RDONLY);
	fd[9] = open("aim/fire.xpm", O_RDONLY);
	fd[10] = open("aim/fire1.xpm", O_RDONLY);
	fd[11] = open("./texture/DOOR_1O.xpm", O_RDONLY);
	fd[12] = open("./texture/DOOR_close.xpm", O_RDONLY);
	while (i < 13)
	{
		if (fd[i] < 0)
			exit(0);
		close(fd[i]);
		i++;
	}
}

void	help_take_image(t_vars *vars)
{
	vars->iam[0] = mlx_xpm_file_to_image(vars->mlx,
			"aim/AnyConv.com__hk53_aim.1.xpm", &vars->weapen.width,
			&vars->n_image.height);
	vars->iam[1] = mlx_xpm_file_to_image(vars->mlx,
			"aim/AnyConv.com__hk53_aim.2.xpm", &vars->weapen.width,
			&vars->n_image.height);
	vars->iam[2] = mlx_xpm_file_to_image(vars->mlx,
			"aim/AnyConv.com__hk53_aim.3.xpm", &vars->weapen.width,
			&vars->n_image.height);
	vars->iam[3] = mlx_xpm_file_to_image(vars->mlx,
			"aim/AnyConv.com__hk53_aim.4.xpm", &vars->weapen.width,
			&vars->n_image.height);
	vars->iam[4] = mlx_xpm_file_to_image(vars->mlx,
			"aim/AnyConv.com__hk53_aim.5.xpm", &vars->weapen.width,
			&vars->n_image.height);
	vars->iam[5] = mlx_xpm_file_to_image(vars->mlx,
			"aim/AnyConv.com__hk53_aim.6.xpm", &vars->weapen.width,
			&vars->n_image.height);
	vars->iam[6] = mlx_xpm_file_to_image(vars->mlx,
			"aim/AnyConv.com__hk53_aim.7.xpm", &vars->weapen.width,
			&vars->n_image.height);
}

void	help_take_image_two(t_vars *vars)
{
	vars->iam[10] = mlx_xpm_file_to_image(vars->mlx, "aim/fire1.xpm",
			&vars->weapen.width, &vars->n_image.height);
	vars->iam[11] = mlx_xpm_file_to_image(vars->mlx, "./texture/DOOR_1O.xpm",
			&vars->door_open.width, &vars->door_open.height);
	vars->iam[12] = mlx_xpm_file_to_image(vars->mlx, "./texture/DOOR_close.xpm",
			&vars->door_close.width, &vars->door_close.height);
}

void	take_image(t_vars *vars)
{
	int	i;

	i = 0;
	check_aim_image();
	vars->iam = ft_calloc(sizeof(void *), 13);
	help_take_image(vars);
	vars->iam[7] = mlx_xpm_file_to_image(vars->mlx,
			"aim/AnyConv.com__hk53_aim.9.xpm", &vars->weapen.width,
			&vars->n_image.height);
	vars->iam[8] = mlx_xpm_file_to_image(vars->mlx,
			"aim/AnyConv.com__hk53_aim.11.xpm", &vars->weapen.width,
			&vars->n_image.height);
	vars->iam[9] = mlx_xpm_file_to_image(vars->mlx, "aim/fire.xpm",
			&vars->weapen.width, &vars->n_image.height);
	help_take_image_two(vars);
	while (i < 13)
	{
		if (vars->iam[i] == NULL)
		{
			free(vars->iam);
			exit(0);
		}
		i++;
	}
}
