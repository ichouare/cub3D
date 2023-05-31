#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
#include     <mlx.h>
#include <stdio.h> 


typedef struct vars{
    void	*mlx;
    void  *mlx_win;
	char ***texture;
    char **store_map;
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
#endif