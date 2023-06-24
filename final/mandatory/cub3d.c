/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyounsi <hyounsi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:12:44 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/22 23:44:42 by hyounsi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_angle_p(t_vars *vars)
{
	t_var	v;

	v.i = 0;
	while (vars->store_map[v.i])
	{
		v.j = 0;
		while (vars->store_map[v.i][v.j])
		{
			if (ft_strchr("NSWE", vars->store_map[v.i][v.j]) != NULL)
			{
				vars->player_x = (int)(v.j * vars->size + vars->size / 2);
				vars->player_y = (int)(v.i * vars->size + vars->size / 2);
				if (vars->store_map[v.i][v.j] == 'N')
					vars->deriction = (3 * M_PI) / 2;
				else if (vars->store_map[v.i][v.j] == 'S')
					vars->deriction = (M_PI) / 2;
				else if (vars->store_map[v.i][v.j] == 'E')
					vars->deriction = 0;
				else if (vars->store_map[v.i][v.j] == 'W')
					vars->deriction = M_PI;
			}
			v.j++;
		}
		v.i++;
	}
}

void	help(t_vars *vars)
{
	int	i;

	i = 0;
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
	init_angle_p(vars);
	if (init_image(vars) == -1)
	{
		if (vars->store_map)
		{
			free2d(vars->store_map);
			free(vars->store_map);
		}
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_vars	vars;

	i = 0;
	init_var(&vars);
	if (argc != 2)
		return (write(2, "ERROR :you must enter one argument\n", 35));
	check_file_name(argv[1]);
	if (parcer_map(&vars, argv[1]) == 0)
		help_exit(&vars);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, vars.width_window,
			vars.height_window, "cub3d");
	help(&vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, key_hook, &vars);
	mlx_hook(vars.mlx_win, 3, 1L << 1, kk, &vars);
	mlx_hook(vars.mlx_win, 17, 1L << 17, red_cross, &vars);
	mlx_loop_hook(vars.mlx, move, &vars);
	mlx_loop(vars.mlx);
}
