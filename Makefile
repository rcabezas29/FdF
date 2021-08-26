# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcabezas <rcabezas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/21 11:54:21 by rcabezas          #+#    #+#              #
#    Updated: 2021/08/26 10:41:08 by rcabezas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

RM = rm -rf

LIBFT = libft

MINILIBX = mlx_ios

MLX = $(MINILIBX)/libmlx.a -lmlx -framework OpenGL -framework AppKit

CC = gcc -Wall -Wextra -Werror -g

INCLUDES = -I $(LIBFT) -I $(MINILIBX) -I ./includes/

SRCS_FDF = fdf.c map.c parse.c draw.c pixel.c bresenham.c

SRCS = $(addprefix srcs/, $(SRCS_FDF))

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@make -C $(MINILIBX)
	@$(CC) $(MLX) $(OBJS) $(INCLUDES) $(LIBFT)/libft.a -o $(NAME) 

%.o: %.c
	@$(CC) -I ./includes -o $@ -c $<

all: $(NAME)
	
clean:
	@$(RM) $(OBJS)
	@make clean -C $(MINILIBX)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(MINILIBX)/libmlx.a
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: 		all fclean clean re