/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichouare <ichouare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:36:15 by hyounsi           #+#    #+#             */
/*   Updated: 2023/06/24 16:16:58 by ichouare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}			t_data;

typedef struct var
{
	int		i;
	int		j;
	int		len_p;
	int		number_of_one;
	int		number_of_zero;
	int		not_val;
	char	*tmp;
	char	**arr;
	char	**color;
	int		new_line;
	int		fd;
	int		fd1;
	int		check;
	int		k;
	int		color_rgb;
	double	dy;
	double	dx;
	double	x;
	double	y;
	double	xinc;
	double	yinc;
	double	s;
	double	stepsx;
	double	stepsy;
	int		offset;
	double	p_d;
	double	angle;
	double	pas;
	char	*d;
	int		offset_y;
	int		r;
}			t_var;

typedef struct vars
{
	int		size;
	void	*mlx;
	void	*mlx_win;
	char	***texture;
	char	**store_map;
	int		map_fd;
	double	player_x;
	double	player_y;
	double	deriction;
	int		len_h;
	int		len_v;
	void	**iam;
	void	*wind2;
	int		width_window;
	int		height_window;
	int		map;
	int		key;
	int		left;
	int		up;
	int		down;
	int		xi;
	int		yi;
	int		xf;
	int		yf;
	int		right;
	int		color_ceil;
	int		f_left;
	int		f_up;
	int		f_down;
	int		f_right;
	int		color_floor;
	t_data	two_d_image;
	char	**image_nswe;
	t_data	weapen;
	t_data	minimap;
	int		x_mouse;
	int		old_x_mouse;
	t_data	n_image;
	t_data	s_image;
	t_data	e_image;
	t_data	w_image;
	t_data	door_close;
	t_data	door_open;
	t_data	main_image;
	double	plane_height;
	double	plane_x_v;
	double	plane_y_v;
	double	plane_des_v;
	double	plane_x_h;
	double	plane_y_h;
	double	plane_des_h;
	int		speed;
	int		pas;
	int		scop;
	int		n;
	int		position;
	int		fire;
	int		move_p;
	double	distance_wall;
}			t_vars;

typedef struct doors
{
	double	*distance;
	double	*distancesoff;
	int		cnt;
}	t_doors;
size_t		found_nl(const char *str, int c);
int			ft_isalpha(char *str);
int			ft_catacter(char *str);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char *s1, char const *s2);
char		*ft_strchr(char *s, int c);
int			create_trgb(int t, int r, int g, int b);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		ft_bzero(void *s, size_t n);
int			ft_lastindex(char *str, int find);
void		*ft_calloc(size_t number, size_t size);
void		check_table(int *table, int len);
char		*get_next_line(int fd);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *nptr);
int			parcer_map(t_vars *vs, char *map_name);
size_t		ft_strlen(char const *p);
void		iterate_width(int *table, char **map, int i, int len);
int			search(char *str, char n);
int			ft_strcmp(char *str1, char *str2);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
void		*ft_calloc(size_t nitems, size_t size);
int			ft_strlen2d(char **s1);
void		ft_bzero(void *s, size_t n);
char		**ft_join2d(char **env, char *var);
char		*ft_itoa(int n);
void		help_move_sprite(t_vars *vars);
void		sprite_move(t_vars *vars);
int			ft_draw(t_vars *vars);
size_t		ft_strlens(char *p, char a);
void		free2d(char **str);
void		iterate_height(int *table, char **map, int i);
int			ft_lenchr(char *s);
int			max_len2d(char **map);
void		free2d(char **str);
void		parcer_one(t_vars *vs, char *map_name, t_var *v);
int			parcer_two(t_vars *vs, t_var *v);
int			check_map_err(t_vars *vs, t_var *v);
int			parcer_three(t_vars *vs, t_var *v);
int			parcer_four(t_vars *vs, t_var *v);
void		ckeck_top(char **map);
void		check_map(char **map);
void		check_aim_image(void);
void		take_image(t_vars *vars);
void		help_check_01(char **map, t_var *v);
int			check_01(char **map);
int			is_print(char *s);
int			get_floor_c(t_vars *vs, t_var *v);
int			get_ceil_c(t_vars *vs, t_var *v);
void		check_file_name(char *map_name);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			check_pixel(t_vars *vars, double sin_value, double cos_value);
void		help_key_hook(int key, t_vars *vars);
int			key_hook(int key, t_vars *vars);
void		ber_floor_ceil(t_vars *vars, int color);
void		help_ber(t_vars *vars, int offset_x, t_data *image, t_var *v);
void		ber(t_vars *vars, int offset_x, t_data *image);
int			kk(int key, t_vars *vars);
void		help_step_h(t_vars *vars, t_var *v, t_doors *doors);
int			ft_step_h(t_vars *vars, double angle, t_doors *doors);
void		help_steps_v(t_vars *vars, t_var *v, t_doors *doors);
int			ft_steps_v(t_vars *vars, double angle, t_doors *doors);
void		v_plane(t_vars *vars, t_var *v);
void		h_plane(t_vars *vars, t_var *v);
void		simple_draw(t_vars *vars, t_var *v);
int			ft_draw(t_vars *vars);
void		help_move(t_vars *vars);
int			move(t_vars *vars);
int			red_cross(t_vars *vars);
int			init_help_image(t_vars *vars);
int			init_image(t_vars *vars);
void		init_var(t_vars *vars);
void		help_exit(t_vars *vars);
int			check_file_ex(t_vars *vs);
void		minimap(t_vars *vars);
void		print_player(t_vars *vars);
void		print_2d_map(t_vars *vars, int i, int j);
void		make_image(t_vars *vars);
void		put_destroy_image(t_vars *vars);
void		create_image(t_vars *vars);
void		v_doors(t_vars *vars, t_var *v, t_doors *doors);
void		draw_door(t_vars *vars, int offset_x, t_data *image);
void		draw_door(t_vars *vars, int offset_x, t_data *image);
void		check_door(t_vars *vars);
void		draw_wall(t_vars *vars, t_var *v, t_doors *doors);
void		v_doors(t_vars *vars, t_var *v, t_doors *doors);
void		help_draw_door(t_vars *vars, int offset_x, t_data *image, t_var *v);
void		draw_door(t_vars *vars, int offset_x, t_data *image);
int			move(t_vars *vars);
#endif