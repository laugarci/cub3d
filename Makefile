# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 17:19:02 by laugarci          #+#    #+#              #
#    Updated: 2023/11/22 15:32:02 by julolle-         ###   ########.fr        #
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

CFILES = cub3d.c \
		 get_next_line/get_next_line.c \
		 get_next_line/get_next_line_utils.c \
		 init_vars.c \
		 game.c \
		 render.c

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
