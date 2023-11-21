# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:19:02 by laugarci          #+#    #+#              #
#    Updated: 2023/11/21 09:55:56 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

HEADER = cub3d.h

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

CFILES = cub3d.c
		 get_next_line/get_next_line.c \
		 get_next_line/get_next_line_utils.c

OBJECTS = $(CFILES:.c=.o)
DEPS	= $(CFILES:.c=.d)

all: subsystems $(NAME)

%.o : %.c Makefile
	@$(CC) $(CFLAGS) -MMD -Imlx -c $< -o $@
	@echo "Compiling $<..."

subsystems:
	make -C $(MLX_PATH) all

$(NAME): $(OBJECTS)
	@$(CC) -o $(NAME) $(MLX_FLAGS) $(MLX_LIB) $(OBJECTS)

clean:
	@$(RM) $(OBJECTS) $(DEPS)
	@make -C $(MLX_PATH) clean

fclean: clean 
	@$(RM) $(NAME)

re: fclean all

norm:
	norminette *.c *.h

-include $(DEPS)

.PHONY: all clean fclean re norm
