#include "get_next_line.h"

int key_hook(int key , t_vars *vars)
{
	 // 13 || 126 >> key N
	 //125 || 1 >> key S
	 //123 || 0 >> key E
	 //124 || 2 >> key W
	printf("%s\n", vars->texture[0][0]);
	printf("%d\n", key);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int ft_draw(t_vars *vars)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	// int k = 40;
	// printf("%c", vars->store_map[i][j]);
	while(vars->store_map[i] != NULL)
	{
		j = 0;
		while(vars->store_map[i][j])
		{
			if(vars->store_map[i][j] == '1')
			{
				x = 0;
				while(x < 20)
				{
					y = 0;
					while(y < 20)
					{
						mlx_pixel_put(vars->mlx, vars->mlx_win, j * 20 + x ,i * 20 + y  , create_trgb(0,100,100,100));
						y++;
					}
					x++;
				}
			}
			if(vars->store_map[i][j] == 'N')
			{
				x = 0;
				while(x < 5)
				{
					y = 0;
					while(y < 5)
					{
						mlx_pixel_put(vars->mlx, vars->mlx_win, j * 20 + x ,i * 20 + y  , create_trgb(0,50,50,100));
						y++;
					}
					x++;
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	t_vars vars;
	vars.store_map = NULL;
	vars.texture = NULL;
	vars.mlx = NULL;
	vars.mlx_win = NULL;
if (parcer_map(&vars) == 0) 
{
	puts("here55");
	return 0;
}


	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 33 * 20 , 14 * 20, "unrecorded");
	//   ft_draw(&vars);
	mlx_loop_hook(vars.mlx, ft_draw, &vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_loop(vars.mlx);
    
}