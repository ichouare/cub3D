#!/bin/sh
NAME = cub3D

BONUS = bonus

CC = cc 

FLAGA = -Wall -Wextra  -Werror 

HEADER = ./mandatory/cub3d.h

HEADER_BONUS = ./bonus_3d/cub3d.h




SRCS =   ./mandatory/cub3d.c ./mandatory/parcer_map.c ./mandatory/ft_split.c  ./mandatory/get_next_line.c ./mandatory/get_next_line_utils.c ./mandatory/ft_atoi.c ./mandatory/tools.c ./mandatory/ft_itoa.c \
	  ./mandatory/map_tools.c ./mandatory/map_tools_1.c  ./mandatory/help_parcer_1.c ./mandatory/help_parcer_2.c ./mandatory/help_parcer_3.c ./mandatory/help_1.c ./mandatory/help_2.c ./mandatory/help_3.c \
	  ./mandatory/help_4.c ./mandatory/help_5.c ./mandatory/tools_1.c \

SRCSB =   ./bonus_3d/cub3d.c ./bonus_3d/parcer_map.c ./bonus_3d/ft_split.c  ./bonus_3d/get_next_line.c ./bonus_3d/get_next_line_utils.c ./bonus_3d/ft_atoi.c ./bonus_3d/tools.c \
 ./bonus_3d/ft_itoa.c  ./bonus_3d/sprite.c  ./bonus_3d/map_tools.c ./bonus_3d/map_tools_1.c  ./bonus_3d/help_parcer_1.c ./bonus_3d/help_parcer_2.c ./bonus_3d/help_parcer_3.c  \
  ./bonus_3d/help_1.c ./bonus_3d/help_2.c ./bonus_3d/help_3.c ./bonus_3d/help_4.c ./bonus_3d/help_5.c ./bonus_3d/tools_1.c ./bonus_3d/minimap.c ./bonus_3d/minimap_tools.c ./bonus_3d/sprite_move.c ./bonus_3d/draw_doors.c \

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCSB:.c=.o)

all: $(NAME)


$(NAME): $(OBJS) 
	$(CC)  $(FLAGA)  -lmlx -framework OpenGL -framework AppKit  $^ -o $@ 

$(BONUS): $(OBJSB) 
	$(CC)  $(FLAGA)  -lmlx -framework OpenGL -framework AppKit  $^ -o $@  
	
%.o : %.c  $(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGA)  -Imlx -c -o $@ $<


clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME)  $(BONUS)

re: fclean all 