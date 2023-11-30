# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julolle- <julolle-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 14:18:02 by laugarci          #+#    #+#              #
#    Updated: 2023/11/30 14:50:55 by julolle-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

HEADER = cub3d.h

SRC_DIR = src/
SRC_DIR_GNL = get_next_line/

SRC_FILES = cub3d.c \
			parser/open_map.c \
			parser/parser_utils.c \
			parser/check_map.c \
			parser/parse_file.c \
			parser/find_img_path.c \
			parser/copy_map.c \
			parser/map_utils.c \
			parser/check_info.c \
			parser/check_paths.c \
			game/game.c \
			game/save_images.c \
			game/render.c \
			game/minimap.c \
			game/movements.c \
			game/print_stripe.c \
			game/cam_movements.c \
			game/utils.c \
			parser/position.c \
			game/mouse_movement.c \
			parser/open_paths.c \
			game/sprite.c \

SRC_FILES_GNL = get_next_line.c \
				get_next_line_utils.c

OBJ_DIR = ./objs/

OBJ_FILES = $(SRC_FILES:.c=.o) $(SRC_FILES_GNL:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

DEP_FILES = $(SRC_FILES:.c=.d) $(SRC_FILES_GNL:.c=.d)
DEPS = $(addprefix $(OBJ_DIR), $(DEP_FILES))

MLX_PATH = mlx/
MLX_LIB = $(MLX_PATH)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
RM = rm -f

INCLUDE = -I libft/ -I get_next_line/ -I inc/

all: m_libft subsystems $(OBJ_DIR) $(NAME)

m_libft:
	@make -C libft/

subsystems:
	@make -C $(MLX_PATH) all

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parser
	@mkdir -p $(OBJ_DIR)/game

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L libft/ -lft -o $@ $(MLX_FLAGS)

#$(OBJ_DIR):
#@mkdir $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	$(CC) $(CFLAGS) -Imlx $(INCLUDE) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR_GNL)%.c $(SRC_DIR_GNL)get_next_line.h Makefile
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

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
	norminette inc/* src/*

-include $(DEPS)

.PHONY: all clean fclean re norm
	 
