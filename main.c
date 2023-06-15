#include "get_next_line.h"


double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
	double *k;
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void f_normalize_angle(t_vars *vars)
{
	 vars->player_angle  = fmod(vars->player_angle , 2 * PI);
	if(vars->player_angle < 0)
			vars->player_angle += 2 * PI;


}


int key_released(int keycode, t_vars *vars)
{
 		vars->keys->key_A = 0;
 		vars->keys->key_w = 0;
 		vars->keys->key_S = 0;
 		vars->keys->key_D = 0;
 		vars->keys->key_T = 0;
 		vars->keys->key_B = 0;
 		vars->keys->key_L = 0;
 		vars->keys->key_R = 0;
		keycode = 0;
		return 0;
}
int key_hook(int key , t_vars *vars)
{
	if(key == 53)
		exit(0);
	if(key == 13)
		vars->keys->key_w = 1;
	if(key == 126)
		vars->keys->key_T = 1;
	if(key == 1)
		vars->keys->key_S = 1;
	if(key == 125)
		vars->keys->key_B = 1;
	if(key == 0)
		vars->keys->key_A = 1;
	if(key == 2)
	{
		//puts("here");
		vars->keys->key_D = 1;
	}
	if(key == 123)
		vars->keys->key_R = 1;
	if(key == 124)
		vars->keys->key_L = 1;
	return 0;
}



int ft_steps(t_vars *vars, double angle)
{
	double stepsx = 0;
	double stepsy = 0;
	double dx = 0;
	double dy = 0;
	int offset = 0;
	
	
	dy = (floor)((vars->player_y) / 64) * 64;
	if(sin(angle) > 0)
	{
		dy += 64; 
	}
	dx =  (vars->player_x) + ((dy - (vars->player_y)) / tan(angle));
	vars->dx = dx;
	vars->dy = dy;
	
	stepsy =  64;

	if(sin(angle) <= 0)
	{
		stepsy = -64;
		offset = -1;
	}
	stepsx = stepsy / tan(angle);
		while(
			(int)vars->dy/64 >= 0 
		&& (int)vars->dx/64 >=  0 
		&& (int)vars->dy/64 <= 13 
		&& (int)vars->dx/64 < (int)strlen(vars->store_map[(int)vars->dy/64])
		&& vars->store_map[(int)(vars->dy + offset) / 64][(int)vars->dx / 64] != '1' )
		{
				vars->dx += stepsx;
				vars->dy += stepsy;
		}	
	vars->hitH = sqrt(pow(vars->dx - vars->player_x, 2) + pow(vars->dy - vars->player_y, 2));
	// if(vars->hitH >= (14* 64))
	// 	vars->hitH = 14 * 64; 
	// if(vars->hitH < 0)
	// 	vars->hitH = 0; 
	return 0;
}


int ft_stepsV(t_vars *vars, double angle)
{
	double stepsx = 0;
	double stepsy = 0;
	double dx = 0;
	double dy = 0;
	int offset = 0;

	dx = (floor)(vars->player_x / 64) * 64;
	if(cos(angle) > 0)
	{
			dx += 64;
	}
	dy = tan(angle) * (dx - vars->player_x) + vars->player_y;
	vars->dxV = dx;
	vars->dyV= dy;
	stepsx +=  64;
	if(cos(angle) < 0)
	{
		stepsx *= -1;
		 offset = -1;
	}
	stepsy = stepsx * tan(angle);
	while((int)(vars->dyV/64) >= 0 && 
	(int)vars->dyV/64 <=  13 &&
	(int)(vars->dxV/64) >=  0 &&
	 (int)vars->dxV/64 < (int)strlen(vars->store_map[(int)vars->dyV / 64])
	  && vars->store_map[(int)vars->dyV / 64][(int)(vars->dxV + offset) / 64] != '1')
		{
				vars->dxV += stepsx;
				vars->dyV += stepsy;	
		}
	 vars->hitV = sqrt(pow(vars->dxV - vars->player_x, 2) + pow(vars->dyV - vars->player_y, 2));
	//  if(vars->hitV > (30* 64))
	// 	vars->hitV= 34 * 64; 
	//  if(vars->hitV < 0)
	// 	vars->hitV = 0; 
	return 0;
}

int get_texture_color(t_data *texture, int x, int y) {
  int byte_offset = (y * texture->line_length) + (x * (texture->bits_per_pixel / 8));
  char *pixel = texture->addr + byte_offset;

  unsigned int color = 0;
  for (int i = 0; i < (texture->bits_per_pixel / 8); i++) {
    color = (color << 8) + (unsigned char)pixel[i];
  }

  return color;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void * ft_facing(t_vars *vars, double angle, int offsetx, int  offsety)
{
	 //int color = 0;
		t_data *img;
	img =  malloc(sizeof(t_data));
	void *buf = NULL;
 if(vars->hitV > vars->hitH)
			{
				if(sin(angle) < 0)
				{
					img->img = vars->texture_N;
					img->addr = mlx_get_data_addr(img->img,  &img->bits_per_pixel, &img->line_length, &img->endian);
					buf = img->addr + (offsety * img->line_length + offsetx * (img->bits_per_pixel / 8));

				}
				else
				{
						img->img = vars->texture_N;
						img->addr = mlx_get_data_addr(img->img,  &img->bits_per_pixel, &img->line_length, &img->endian);
						buf = img->addr + (offsety * img->line_length + offsetx * (img->bits_per_pixel / 8));
				}
				
			}
		else  
			{
				if(cos(angle) < 0)
				{
					img->img = vars->texture_N;
					img->addr = mlx_get_data_addr(img->img,  &img->bits_per_pixel, &img->line_length, &img->endian);
					buf = img->addr + (offsety * img->line_length + offsetx * (img->bits_per_pixel / 8));

				} 
				else
				{
					img->img = vars->texture_N;
					img->addr = mlx_get_data_addr(img->img,  &img->bits_per_pixel, &img->line_length, &img->endian);
					buf = img->addr + (offsety * img->line_length + offsetx * (img->bits_per_pixel / 8));
				}
			}
	
	
	return buf;

}
// void ft_dda(t_vars *vars, double x, double y, double Dx, double Dy,t_data *img)
// {
// 	int dtx = 0;
// 	int dty = 0;
// 	int steps = 0;
// 	double xinc = 0;
// 	double yinc = 0;
// 	void *buf = NULL;
// 	int offsety = 0;
// 	int offsetx = 0;	
// 	double walltopixel = 0;

// 	int m = 1;

// 	dtx = Dx  - x;
// 	dty = Dy - y;
// 	if(abs((int)(dtx)) > abs((int)(dty)))
// 		steps = abs((int)(dtx));
// 	else
// 		steps = abs((int)(dty));
// 	xinc = (double)dtx / (double)steps;
// 	yinc = (double)dty / (double)steps;
// 	walltopixel = y;
// 	// if(walltopixel  < 0)
// 	// 	walltopixel = 0;
// 	if(vars->hitH <= vars->hitV)
// 	{
// 		offsetx = (fmod(vars->dx , 64)/64.0) * 64;
// 	}
// 	else
// 		offsetx = (fmod(vars->dyV , 64)/64.0) * 64;
// 	while(m <= steps)
// 	{
// 		if(y < 0 || y >= 13*64)
// 			y = 0;
// 		offsety = abs((int)(y - walltopixel)) * ((double)(64) / (Dy - walltopixel));
// 		//unsigned int  color =  *(unsigned int  *)ft_facing(vars, angle, offsetx, offsety);
// 		buf = img->addr + (offsety * img->line_length + offsetx * (int)(img->bits_per_pixel / 8));
// 		my_mlx_pixel_put(vars->data,(int)x  , (int)y  ,  *(unsigned int *)buf);
// 		x += xinc;
// 		y += yinc;
// 		m++;
// 	}
// }

void ft_floor(t_vars *vars, double x, double y, double Dx, double Dy,int color)
{
	int dtx = 0;
	int dty = 0;
	int steps = 0;
	double xinc = 0;
	double yinc = 0;


	

	int m = 1;

	dtx = Dx  - x;
	dty = Dy - y;
	if(abs((int)(dtx)) > abs((int)(dty)))
		steps = abs((int)(dtx));
	else
		steps = abs((int)(dty));
	xinc = (double)dtx / (double)steps;
	yinc = (double)dty / (double)steps;

	while(m <= steps)
	{
		if(y < 0 || y >= 13*64)
			y = 0;
		// offsety = abs((int)(y - walltopixel)) * ((double)(64) / (Dy - walltopixel));
		// //unsigned int  color =  *(unsigned int  *)ft_facing(vars, angle, offsetx, offsety);
		// buf = img->addr + (offsety * img->line_length + offsetx * (int)(img->bits_per_pixel / 8));
		my_mlx_pixel_put(vars->data,(int)x  , (int)y  ,  color);
		x += xinc;
		y += yinc;
		m++;
	}
}

void ft_dda(t_vars *vars, double x, double y, double Dx, double Dy,t_data *img)
{
	int dtx = 0;
	int dty = 0;
	int steps = 0;
	double xinc = 0;
	double yinc = 0;
	void *buf = NULL;
	int offsety = 0;
	int offsetx = 0;	
	double walltopixel = 0;

	int m = 1;

	dtx = Dx  - x;
	dty = Dy - y;
	if(abs((int)(dtx)) > abs((int)(dty)))
		steps = abs((int)(dtx));
	else
		steps = abs((int)(dty));
	xinc = (double)dtx / (double)steps;
	yinc = (double)dty / (double)steps;
	walltopixel = y;
	// if(walltopixel  < 0)
	// 	walltopixel = 0;
	if(vars->hitH <= vars->hitV)
	{
		offsetx = (fmod(vars->dx , 64)/64.0) * 64;
	}
	else
		offsetx = (fmod(vars->dyV , 64)/64.0) * 64;
	while(m <= steps)
	{
		if(y < 0 || y >= 13*64)
			y = 0;
		offsety = abs((int)(y - walltopixel)) * ((double)(64) / (Dy - walltopixel));
		//unsigned int  color =  *(unsigned int  *)ft_facing(vars, angle, offsetx, offsety);
		buf = img->addr + (offsety * img->line_length + offsetx * (int)(img->bits_per_pixel / 8));
		my_mlx_pixel_put(vars->data,(int)x  , (int)y  ,  *(unsigned int *)buf);
		x += xinc;
		y += yinc;
		m++;
	}
	
}
void draw_wall(t_vars *vars, int i, double angle)
{
	double withrayon = 0;
	double heightrayon = 0;
	double rayDistance = 0;
	t_data *img;
	img =  malloc(sizeof(t_data));
	
	if(vars->hitV <= vars->hitH)
		rayDistance = vars->hitV * cos(angle - vars->player_angle);
	else
		rayDistance = vars->hitH * cos(angle - vars->player_angle);
	double windowWith = 33*64;
 double windowHeight = 13*64;
	double wallheightStrip = 0;
	double distancetopeoject = (double)(windowWith / 2) / tan(30 * (PI / 180));
	wallheightStrip = (((double)64 / rayDistance) * distancetopeoject);
	withrayon = i;
	heightrayon = (windowHeight / 2 ) - (wallheightStrip / 2);
	vars->wallStripHeight = wallheightStrip;
	 ft_floor(vars, i,  0, i, heightrayon , create_trgb(1, 255, 225, 100));
	if(vars->hitV > vars->hitH)
			{
				if(sin(angle) < 0)
				{
					img->img = vars->texture_N;
					img->addr = mlx_get_data_addr(img->img,  &img->bits_per_pixel, &img->line_length, &img->endian);
				}
				else
				{
						img->img = vars->texture_N;
						img->addr = mlx_get_data_addr(img->img,  &img->bits_per_pixel, &img->line_length, &img->endian);
				}
				
			}
		else  
			{
				if(cos(angle) < 0)
				{
					img->img = vars->texture_N;
					img->addr = mlx_get_data_addr(img->img,  &img->bits_per_pixel, &img->line_length, &img->endian);
				} 
				else
				{
					img->img = vars->texture_N;
					img->addr = mlx_get_data_addr(img->img,  &img->bits_per_pixel, &img->line_length, &img->endian);
				}
			}
				ft_dda(vars, withrayon, heightrayon, withrayon, (windowHeight / 2 ) + (wallheightStrip / 2), img);
			 ft_floor(vars, i,  heightrayon + wallheightStrip, i,(13*64), create_trgb(5, 255, 225, 255));
	}

void ft_move(t_vars *vars)
{
		double x =  0;
	double y =  0;
	double j = 0;
	double i = 0;
	// double movespped = 2;
	if(vars->keys->key_T == 1)
	{
			x = vars->player_x + cos(vars->player_angle) * 20;
			y  = vars->player_y + sin(vars->player_angle) * 20;
			i = x;
			j = y;
			while(i <= x + 10)
			{
				j = y;
				while(j <= y + 10)
				{
					if(vars->store_map[(int)(j) / 64][(int)(i) / 64] == '1')
					{
							return ;
					}
					j++;
				}
				i++;
			}
			vars->player_y += sin(vars->player_angle) * 20; 
			vars->player_x += cos(vars->player_angle)* 20;

	}
	if(vars->keys->key_w == 1)
	{
			
			x = vars->player_x;
			y  = vars->player_y + sin(vars->player_angle) * 20;
			i = x;
			j = y;
			while(i <= x + 10)
			{
				j = y;
				while(j <= y + 10)
				{
					if(vars->store_map[(int)(j) / 64][(int)(i) / 64] == '1')
					{
							return ;
					}
					j++;
				}
				i++;
			}
			vars->player_y += sin(vars->player_angle) * 20; 

	}
	if( vars->keys->key_B == 1)
	{

			x = vars->player_x - cos(vars->player_angle) * 20;
			y  = vars->player_y - sin(vars->player_angle) * 20;
			i = x;
			j = y;
			while(i <= x + 10)
			{
				j = y;
				while(j <= y + 10)
				{
					if(vars->store_map[(int)(j) / 64][(int)(i) / 64] == '1')
					{
							return ;
					}
					j++;
				}
				i++;
			}
			vars->player_y -= sin(vars->player_angle) * 20; 
			vars->player_x -= cos(vars->player_angle)* 20;
	}
	if(vars->keys->key_S  == 1)
	{

			x = vars->player_x;
			y  = vars->player_y - sin(vars->player_angle) * 20;
			i = x;
			j = y;
			while(i <= x + 10)
			{
				j = y;
				while(j <= y + 10)
				{
					if(vars->store_map[(int)(j) / 64][(int)(i) / 64] == '1')
					{
							return ;
					}
					j++;
				}
				i++;
			}
			vars->player_y -= sin(vars->player_angle) * 20; 
	}
	if(vars->keys->key_D == 1)
	{
		// puts("hereX");
			x = vars->player_x + cos(vars->player_angle + ( PI / 2)) * 20;
			y  = vars->player_y ;
			i = x;
			j = y;
			while(i <= x + 10)
			{
				j = y;
				while(j <= y + 10)
				{
					if(vars->store_map[(int)(j) / 64][(int)(i) / 64] == '1')
					{
							return ;
					}
					j++;
				}
				i++;
			}
			vars->player_x += cos(vars->player_angle + ( PI / 2))* 20;
	}
	if(vars->keys->key_A == 1)
	{
		puts("hereX");
			x = vars->player_x - cos(vars->player_angle + ( PI / 2)) * 20;
			y  = vars->player_y ;
			i = x;
			j = y;
			while(i <= x + 10)
			{
				j = y;
				while(j <= y + 10)
				{
					if(vars->store_map[(int)(j) / 64][(int)(i) / 64] == '1')
					{
							return ;
					}
					j++;
				}
				i++;
			}

			vars->player_x -= cos(vars->player_angle + ( PI / 2) )* 20;
	}
	if(vars->keys->key_R == 1)
	{
			vars->turn_direction = -1;
			vars->player_angle -=  0.3;
	}
	if(vars->keys->key_L  == 1)
	{
			vars->turn_direction = + 1;
			vars->player_angle +=0.3;
	}
	f_normalize_angle(vars);
} 



int ft_draw(t_vars *vars)
{
	
	int i = 0;
	int j = 0;

	int x = 0;
	int column = 0;
	vars->data->img = mlx_new_image(vars->mlx, (33 * 64), (14 * 64));
	vars->data->addr = mlx_get_data_addr(vars->data->img,  &vars->data->bits_per_pixel, &vars->data->line_length, &vars->data->endian);
	mlx_clear_window(vars->mlx, vars->mlx_win);
	ft_move(vars);
	while(vars->store_map[i] != NULL)
	{
		j = 0;
		while(vars->store_map[i][j])
		{
			if(j  == (int)((vars->player_x ) / 64) && (int)((vars->player_y) / 64) == i )
			{
				double angle = vars->player_angle - (vars->field_of_view / 2);
				// x = -10;
				// while(x  < 0)
				// {
				// 	y = 0;
				// 	while(y < 10)
				// 	{  
				// 		k = 0;
				// 		while(k < 20)
				// 		{
						
				// 					// mlx_pixel_put(vars->mlx, vars->mlx_win,  (vars->player_x)  +  cos(vars->player_angle) * k ,  (vars-> player_y)  + sin(vars->player_angle) * k, create_trgb(0,100,100,100));
				// 				k++;
				// 		}	
				// 		//mlx_pixel_put(vars->mlx, vars->mlx_win, (vars->player_x)  + x +  cos(vars->player_angle)  , vars->player_y + y  + sin(vars->player_angle), create_trgb(0,200,50,100));

				// 		y++;
				
				// 	}

				// 	x++;
				// }
				//puts("here");
				while(angle <= vars->player_angle + (vars->field_of_view / 2) )
					{
					 
					ft_steps(vars, angle);
					ft_stepsV(vars,  angle);
					if(vars->hitV <= vars->hitH)
					{
						vars->dx = vars->dxV;
						vars->dy = vars->dyV;
					}
					//ft_dda(vars, vars->player_x, vars->player_y, vars->dx, vars->dy, angle);
			draw_wall(vars, column, angle);
					
					
					vars->hitH = 0;
					vars->hitV = 0;
					angle += vars->field_of_view / vars->num_rays;
				
					column++;
					}
				x = 0;	
			}
			// if(vars->store_map[i][j] == '1')
			// {
			// 	x = 0;
			// 	while(x < 64)
			// 	{
			// 		y = 0;
			// 		while(y < 64)
			// 		{
			// 				mlx_pixel_put(vars->mlx, vars->mlx_win, j * 64 + x  , i * 64 + y  , create_trgb(0,100,100,100));
			// 			y++;
			// 		}
			// 		x++;
			// 	}
			// }
			j++;
		
		}
		i++;
}
mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data->img, 0, 0);
mlx_destroy_image(vars->mlx, vars->data->img);
		vars->keys->key_A = 0;
 		vars->keys->key_w = 0;
 		vars->keys->key_S = 0;
 		vars->keys->key_D = 0;
 		vars->keys->key_T = 0;
 		vars->keys->key_B = 0;
 		vars->keys->key_L = 0;
 		vars->keys->key_R = 0;
	return (0);

}



int	main(void)
{
	
	t_vars *vars;
	vars = malloc(sizeof(t_vars));
	vars->store_map = NULL;
	vars->texture = NULL;
	vars->mlx = NULL;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->radius = 3;
	vars->speed = 2;
	vars->player_angle = (PI / 2);
	vars->field_of_view = 60 *(PI / 180);
	vars->turn_direction = 0;
	vars->walk_direction = 0;
	vars->isRayFacingUp = 0;
	vars->player_lx  = 0 ;
	vars->Wall_strip_width = 1;
	vars->num_rays = (64 * 33);
	// vars.stepsy = 0;
	// vars->rays_list = malloc(vars.num_rays * sizeof(int));
	vars->keys = malloc(sizeof(t_keys));
	vars->mlx_win = NULL;
	vars->keys->key_A = 0;
	vars->keys->key_w = 0;
	vars->keys->key_S = 0;
	vars->keys->key_D = 0;
	vars->keys->key_T = 0;
	vars->keys->key_B = 0;
	vars->keys->key_L = 0;
	vars->keys->key_R = 0;
	vars->data = malloc(sizeof(t_data));
	int height;
	int width;
	vars->img_E = "./wall_N.xpm";
	// vars->img_W = "./path_to_the_west_texture.xpm";
	// vars->img_S = "./path_to_the_south_texture.xpm";
	// vars->img_N = "./path_to_the_north_texture.xpm";
	
if (parcer_map(vars) == 0) 
{
	// puts("here55");
	return 0;
}
	vars->mlx = mlx_init();
	vars->texture_N = mlx_xpm_file_to_image(vars->mlx,vars->img_E, &width, &height);
	// vars->texture_E = mlx_xpm_file_to_image(vars->mlx,vars->img_E, &width, &height);
	// vars->texture_S = mlx_xpm_file_to_image(vars->mlx,vars->img_S, &width, &height);
	// vars->texture_W = mlx_xpm_file_to_image(vars->mlx,vars->img_W, &width, &height);
	if(vars->texture_N == NULL)
	{
		exit(0);
	}
	vars->mlx_win = mlx_new_window(vars->mlx, ( 33 * 64) , (14 * 64), "unrecorded");

	int i = 0;
	int j = 0;
	while(vars->store_map[i])
	{
		j = 0;
		while(vars->store_map[i][j])
		{
		
			if(vars->store_map[i][j] == 'N')
			{
				vars->player_x = j * 64 +10;
				vars->player_y = i * 64 +10;
			}
			j++;
		}
		i++;
	}
	
	mlx_hook(vars->mlx_win, 2, 1L << 2, &key_hook, vars);


	mlx_hook(vars->mlx_win,3,  0, &key_released, vars);

	mlx_loop_hook(vars->mlx, ft_draw, vars);

	
	mlx_loop(vars->mlx);
    
}