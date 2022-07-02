# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 14:10:13 by jiyseo            #+#    #+#              #
#    Updated: 2022/07/03 03:14:36 by jiyseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN		= a.out
DIR_MLX	= mlx
DIR_FT	= Libft
DIR_PR	= ft_printf
LIB_MLX = libmlx.dylib
LIB_FT	= $(DIR_FT)/libft.a
LIB_PR	= $(DIR_PR)/libftprintf.a 
SRCS	= so_long_bonus.c \
		  so_long_utils_bonus.c \
		  map_bonus.c \
		  map_utils_bonus.c \
		  map_state_bonus.c \
		  image_bonus.c \
		  key_bonus.c \
		  get_next_line_bonus.c \
		  get_next_line_utils_bonus.c
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall
INCS	= -I./$(DIR_MLX) -I./$(DIR_FT) -I./$(DIR_PR)/

.PHONY: clean

all: $(BIN)

$(LIB_MLX):
	make -C $(DIR_MLX)
	cp $(DIR_MLX)/$(LIB_MLX) .

$(LIB_FT):
	make -C $(DIR_FT)

$(LIB_PR):
	make -C $(DIR_PR)

$(BIN): $(LIB_MLX) $(LIB_FT) $(OBJS)
	$(CC) -o $@ $(OBJS) -L./$(DIR_FT) -lft -L./$(DIR_PR) -lftprintf $(LIB_MLX)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f *.o $(LIB_MLX)
	make clean -C $(DIR_MLX)
	make clean -C $(DIR_FT)
	make clean -C $(DIR_PR)
