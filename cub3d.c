// #include "get_next_line.h"
	if(vars->hitV <= vars->hitH)
		{
			if(cos(vars->player_angle) <= 0)
				mlx_pixel_put( vars->mlx, vars->mlx_win, floor(x), floor(y), create_trgb(0, 250, 100, 50));
			else
				mlx_pixel_put( vars->mlx, vars->mlx_win, floor(x), floor(y), create_trgb(0, 250, 100, 250));
		}
		else
		{
			// puts("here");
			if(sin(vars->player_angle) <= 0)
				mlx_pixel_put( vars->mlx, vars->mlx_win, floor(x), floor(y), create_trgb(0, 250, 250, 50));
			else
				mlx_pixel_put( vars->mlx, vars->mlx_win, floor(x), floor(y), create_trgb(0, 100, 100, 50));

double PI = 3.14159;

// void ft_facingPlayer(t_vars *vars)
// {
// 	if(vars->player_angle > 0 &&  vars->player_angle < PI)
// 	{
// 		vars->isRayFacingUp = 0;
// 		vars->isRayFacingDown = 1;
// 	}
// 	else
// 	{
// 		puts("heredsfgd");
// 		vars->isRayFacingDown = 0;
// 		vars->isRayFacingUp = 1;

// 	}
// 	if(vars->player_angle >= (PI / 2) &&  vars->player_angle <=  (( 3 * PI)  / 2))
// {
// 		vars->isRayFacingLeft = 1;
// 		vars->isRayFacingRight = 0;

// }
// 	else
// 	{
// 		vars->isRayFacingLeft = 0;
// 		vars->isRayFacingRight = 1;
		
// 	}
// }

int ft_find_first_intersection(t_vars *vars, double angle)
{
	double dx = 0;
	double dy = 0;

	double lenghty;
	
	dy = (int)(((int)(vars->player_y + vars->player_yD) / 32) * 32);
	if(sin(angle)> 0)
	{
		dy += 32; 
	}
	lenghty = dy - (vars->player_y + vars->player_yD);
	dx =  (vars->player_x + vars->player_xD) + ((lenghty) / tan(angle));
	vars->dx = dx;
	vars->dy = dy;
	if(dy <= 0 || dy >= ( 14 * 32) || dx <= 0 || dx >= ( 33 * 32) || vars->store_map[(int)(dy/ 32)][(int)(dx / 32)] == '1')
	{
		vars->hitH = dx * cos(angle);
		return  1;
	}
	return 0;
}

int ft_find_first_intersectionV(t_vars *vars, double angle)
{
	double dx = 0;
	double dy = 0;

	double lenghty;
	
	dx = (int)(((int)(vars->player_x + vars->player_xD) / 32) * 32);
	if(cos(angle)> 0)
	{
			
			dx+=32;
	}
	lenghty = dx - (vars->player_x + vars->player_xD);
	dy = (tan(angle) * lenghty  ) + (vars->player_y + vars->player_yD);
	vars->dxV = dx;
	vars->dyV= dy;
	// printf("%f\n", floor(dx));
	// printf("%f\n", floor(dy));
	// exit(0);
	if(dx <= 0 || dx >= ( 33 * 32) || dy <= 0 || dy >= ( 14 * 32) || vars->store_map[(int)(dy/ 32)][(int)(dx / 32)] == '1')
	{

		vars->hitV = dx / cos(angle);
		return  1;
	}
	return 0;
}



int ft_steps(t_vars *vars, double angle)
{
	double stepsx = 0;
	double stepsy = 0;
	int findwall = 0;
	stepsy +=  32;
	if(sin(angle) < 0)
	{
		puts("here");
		stepsy *= -1;
	}
	stepsx = stepsy / tan(angle);
	
	// if((stepsx > 0  && vars->isRayFacingLeft == 1) || (vars->isRayFacingRight == 1 && stepsx < 0))
	// 	stepsx *= -1;
	while(findwall == 0)
	{
		if(vars->dy <= 0 || vars->dx <=  0 || vars->dx >= (33 * 32) || vars->dy >= ( 14 * 32) || vars->store_map[(int)(vars->dy / 32)][(int)(vars->dx / 32)] == '1' )
		{
			
			vars->hitH = vars->dx / cos(angle);;
			findwall = 1;
		}
		else
		{
				vars->dx += stepsx;
				vars->dy += stepsy;	
		}
	}	
		
	return 0;
}
int ft_stepsV(t_vars *vars, double angle)
{
	double stepsx = 0;
	double stepsy = 0;
	int findwall = 0;
	stepsx +=  32;
	if(cos(angle) < 0)
	{
		stepsx *= -1;
	}
	stepsy = stepsx * tan(angle);
	while(findwall == 0)
	{

		if(vars->dy <= 0 || vars->dx <= 0 || vars->dx >=  ( 33 * 32) || vars->dy >= ( 14 * 32) || vars->store_map[(int)(vars->dyV / 32)][(int)(vars->dxV / 32)] == '1')
		{
			vars->hitV = vars->dxV / cos(angle);
			findwall = 1;
		}
		else
		{
				vars->dxV += stepsx;
				vars->dyV += stepsy;	
		}
	}
	return 0;
}



int key_hook(int key , t_vars *vars)
{
	 int postionx = 0;
	 int postiony = 0;
	
	if(key == 53)
		exit(0);
	if((key == 13 || key == 126))
	{
		if(vars->store_map[(int)(vars->player_y +   vars->player_yD +  sin(vars->player_angle)*3) / 32][(int)(vars->player_x  + vars->player_xD +  cos(vars->player_angle)*3) / 32] != '1')
		{
			vars->player_y += sin(vars->player_angle) * 3; 
			vars->player_x += cos(vars->player_angle)* 3;

		} 
	}
	if(key  == 1 || key == 125)
	{
		
		postionx = (int)(vars->player_x  + vars->player_xD +  cos(vars->player_angle)) / 32;
		postiony = (int)(vars->player_y +  vars->player_yD +  sin(vars->player_angle)) / 32;

		if(vars->store_map[postiony][postionx] != '1')
		{
			vars->player_y -= sin(vars->player_angle) * 3;
			vars->player_x -= cos(vars->player_angle) * 3;

		}
	
	}	
	if(key == 0 || key == 123)
	{
			vars->turn_direction = -1;
			vars->player_angle -= 0.1;
	}
	if(key == 2 || key == 124)
	{
			vars->turn_direction = + 1;
			vars->player_angle += 0.1;
	}
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


void ft_dda(t_vars *vars)
{
	double dtx = 0;
	double dty = 0;
	double steps = 0;
	double xinc = 0;
	double yinc = 0;
	double x = 0;
	double y = 0;
	//double done = sqrt(pow(vars->dx - (vars->player_x + vars->player_xD), 2) + pow(vars->dy - (vars->player_y + vars->player_yD), 2));
	//double dtwo = sqrt(pow(vars->dxV - (vars->player_x + vars->player_xD), 2) + pow(vars->dyV - (vars->player_y + vars->player_yD), 2));
	// printf("%f\n",done );
	// printf("%f\n",dtwo);
	
	double m = 0;
	x = vars->player_x +  vars->player_xD;
	y = vars->player_y +  vars->player_yD;
	dtx = vars->dx  - x;
	dty = vars->dy - y;
	if(abs((int)(dtx)) > abs((int)(dty)))
		steps = abs((int)(dtx));
	else
		steps = abs((int)(dty));
	xinc = dtx / steps;
	yinc = dty / steps;
	while(m <= steps)
	{
		mlx_pixel_put(vars->mlx, vars->mlx_win,(int)(x), (int)(y),  create_trgb(0,250,100,5));
		x += xinc;
		y += yinc;
		m++;
	}
}

int ft_draw(t_vars *vars)
{
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int r = 0;
	mlx_clear_window(vars->mlx, vars->mlx_win);
	while(vars->store_map[i] != NULL)
	{
		j = 0;
		while(vars->store_map[i][j])
		{
			if(vars->store_map[i][j] == '1')
			{
				x = 0;
				while(x < 32)
				{
					y = 0;
					while(y < 32)
					{
							mlx_pixel_put(vars->mlx, vars->mlx_win, j * 32 + x  , i * 32 + y  , create_trgb(0,100,100,100));
						y++;
					}
					x++;
				}
			}
			
		if(r == 0)
		{
			if(vars->store_map[i][j] == 'N')
			{
				vars->player_x = j * 32;
				vars->player_y = i * 32;
				r++;
			}

		}
			if(j  == (int)((vars->player_x + vars->player_xD) /32) && (int)((vars->player_y + vars->player_yD) /32) == i )
			{

				int k = 0;
				double angle = 0;	
				x = 0;
				angle = vars->player_angle - (20 * (PI / 180));
				while(angle <= vars->player_angle)
					{
					//ft_facingPlayer(vars);
					if(ft_find_first_intersection(vars,  angle) == 0)
						ft_steps(vars, angle);
					if(ft_find_first_intersectionV(vars,  angle) == 0)
						ft_stepsV(vars,angle);
					if(vars->hitV < vars->hitH)
					{
						puts("here");
						vars->dx = vars->dxV;
						vars->dy = vars->dyV;
					}else
						puts("1");
					ft_dda(vars);
					vars->hitH = 0;
					vars->hitV = 0;
					angle += ((PI / 180));
					}
					angle = 0;
					
					x = 0;
				while(x  < 10)
				{
					y = 0;
					while(y < 10)
					{  
						k = 0;
						
						while(k < 30)
						{
							mlx_pixel_put(vars->mlx, vars->mlx_win,  (vars->player_x)  + vars->player_xD  +  cos(vars->player_angle) * k ,  (vars-> player_y )  + vars->player_yD + sin(vars->player_angle) * k, create_trgb(0,100,100,100));
							k++;
						}	
						//mlx_pixel_put(vars->mlx, vars->mlx_win, (vars->player_x)  + x + vars->player_xD +  cos(vars->player_angle)  , vars->player_y + y + vars->player_yD + sin(vars->player_angle), create_trgb(0,200,50,100));

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
	vars.player_x = 0;
	vars.player_y = 0;
	vars.player_xD = 0;
	vars.player_yD = 0;
	// vars.radius = 3;
	vars.speed = 2;
	vars.player_angle = PI / 2;
	vars.rotationspeed = 2 * (PI/ 180); 
	vars.turn_direction = 0;
	vars.walk_direction = 0;

	vars.mlx_win = NULL;
if (parcer_map(&vars) == 0) 
{
	// puts("here55");
	return 0;
}


	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 33 * 32 , 14 * 32, "unrecorded");
	//   ft_draw(&vars);
	
	// mlx_destroy_window(vars.mlx,vars.mlx_win);
	mlx_loop_hook(vars.mlx, ft_draw, &vars);
	mlx_hook(vars.mlx_win, 2, 1L << 2, &key_hook, &vars);
	// mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_loop(vars.mlx);
    
}


int ft_stepsV(t_vars *vars, double angle)
{
	double stepsx = 0;
	double stepsy = 0;
	double dx = 0;
	double dy = 0;

	dx = (int)(vars->player_x / 32) * 32;
	if(cos(angle) < 0)
	{
			dx *= -1;
	}
	dy = tan(angle) * dx - vars->player_x + vars->player_y;
	vars->dxV = dx;
	vars->dyV= dy;
	stepsx +=  32;
	if(cos(angle) > 0)
	{
		stepsx = +32;
	}
	puts("here");
	stepsy = stepsx * tan(angle);
	while(vars->dy >= 0 && vars->dx >=  0 && (int)vars->dx/32 <= 33 && (int)vars->dy/32 <=  14 && vars->store_map[(int)vars->dyV / 32][(int)vars->dxV / 32] != '1')
		{
				vars->dxV += stepsx;
				vars->dyV += stepsy;	
		}
		// vars->hitV = cos(angle) *  vars->dxV;
	return 0;
}