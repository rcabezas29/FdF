# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 11:54:21 by rcabezas          #+#    #+#              #
#    Updated: 2021/06/23 10:36:09 by rcabezas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
    LIBS := -lz -framework OpenGL -framework Appkit
    MLX = mlx_ios/libmlx.dylib
    MINILIBX = mlx_ios
    INCLUDES = -I/usr/include -I. -Iincludes/ -I $(MINILIBX) -I $(LIBFT)
endif

NAME = FdF

CFLAGS = gcc -Werror -Wextra -Wall

SRCS_FDF = 	fdf.c

SRCS = $(addprefix srcs/, $(SRCS_FDF))

OBJS = $(SRCS:.c=.o)

LIBFT = libft

RM = rm -rf

LIB = $(addprefix $(INCLUDES_PATH)/, fdf.h)

all: $(NAME)

$(NAME) : $(OBJS)
	@make -C $(MINILIBX)
	@make -C $(LIBFT)
	@$(CFLAGS) -I $(INCLUDES) $(LIBFT)/libft.a $(MLX) $(OBJS) -o $(NAME)
	@cp $(MLX) ./

%.o: %.c
	@$(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@make clean -C ./mlx_ios
	@make clean -C $(LIBFT)

fclean:			clean
	@$(RM) $(NAME)
	@$(RM) libmlx.a libmlx.dylib
	@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re
