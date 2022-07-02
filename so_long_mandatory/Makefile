# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyseo <jiyseo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 14:10:13 by jiyseo            #+#    #+#              #
#    Updated: 2022/07/03 03:06:59 by jiyseo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN		= a.out
DIR_MLX	= mlx
DIR_FT	= Libft
DIR_PR	= ft_printf
LIB_MLX = libmlx.dylib
LIB_FT	= $(DIR_FT)/libft.a
LIB_PR	= $(DIR_PR)/libftprintf.a 
SRCS	= so_long.c \
		  so_long_utils.c \
		  map.c \
		  map_utils.c \
		  map_state.c \
		  image.c \
		  key.c \
		  get_next_line.c \
		  get_next_line_utils.c
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
