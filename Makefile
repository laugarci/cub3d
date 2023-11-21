# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 11:55:50 by laugarci          #+#    #+#              #
#    Updated: 2023/11/21 11:58:09 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

HEADER = cub3d.h

SRC_DIR = src/
SRC_FILES = cub3d.c \
			check_args.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c

OBJ_DIR = objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

DEP_FILES = $(SRC_FILES:.c=.d)
DEPS = $(addprefix $(OBJ_DIR), $(DEP_FILES))

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
RM = rm -f

INCLUDE = -I include/ -I libft/include/ -I inc/

all: m_libft subsystems $(NAME)

m_libft:
	@make -C libft/

subsystems:
	make -C $(MLX_PATH) all

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) -o $(NAME) $(MLX_FLAGS) $(MLX_LIB) $(CFLAGS) $(OBJS) -L libft/ -lft

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBFT) Makefile
	$(CC) $(CFLAGS) -Imlx $(INCLUDE) -Iinclude/ -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)
	@make -C libft/ clean
	@make -C $(MLX_PATH) clean

fclean: clean
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all

norm:
	norminette src/*.c

-include $(DEPS)

.PHONY: all clean fclean re norm

