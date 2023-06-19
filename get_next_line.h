#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include     <mlx.h>
#include <stdio.h> 
#include <math.h>
 #include <string.h>

typedef struct keys {
    int key_w;
    int key_S;
    int key_A;
    int key_D;
    int key_T;
    int key_B;
    int key_R;
    int key_L;
} t_keys;

typedef struct s_data {
  void *img;
  char *addr;
  int bits_per_pixel;
  int line_length;
  int endian;
} t_data;
typedef struct vars{
    void	*mlx;
    void  *mlx_win;
    t_keys	*keys;
	char ***texture;
    char **store_map;
    double   player_x;
    double  player_y;
    double  player_xD;
    double  player_yD;
    double  player_lx;
    double player_angle;
    char **imgs;
     double radius;
    int Wall_strip_width; 
    double *rays_list;
    int turn_direction; // -1 if left or 1 if right
    int walk_direction; // -1 if back or 1 if front
    int speed;
    double field_of_view;
    int num_rays; 
    double stepsx;
    double stepsy;
    double x;
	double y;
    double dx;
    double dxV;
    double dyV;
    t_data *data;
    double hitH;
    double hitV;
    int *fl_floor;
    int *fl_ceil;
    int doors; //
    int isRayFacingUp;
    int isRayFacingDown;
    int isRayFacingRight;
    double wallStripHeight;
    unsigned int	**buf;
    void *texture_N;
    void *texture_W;
    void *texture_S;
    void *texture_E;
    void *img_N;
    void *img_S;
    void *img_W;
    void *img_E;
    void *attack;
    void *attack_img;
    void *sprite;
    int height;
	int width;
    double dy;

    

} t_vars;





size_t	found_nl(const char *str, int c);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t number, size_t size);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int	    ft_atoi(const char *nptr);
int parcer_map(t_vars *vs);
int ft_draw(t_vars *vars);
int	create_trgb(int t, int r, int g, int b);
int ft_strlen(char *str);
#endif