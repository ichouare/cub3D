#!/bin/sh
NAME = cub3D

CC = cc 

FLAG = -Wall -Wextra  -Werror 

HEADER = ./get_next_line.h


FLAGS = -lmlx -framework OpenGL -framework AppKit


SRCS =   cub3d.c parcer_map.c ft_split.c  get_next_line.c get_next_line_utils.c ft_atoi.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJS) 
	$(CC)  $(FLAG)  -lmlx -framework OpenGL -framework AppKit  $^ -o $@  
	
%.o : %.c  $(HEADER)
	$(CC) $(FLAG)  -Imlx -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all 