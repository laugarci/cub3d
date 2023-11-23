# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laugarci <laugarci@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 09:51:44 by laugarci          #+#    #+#              #
#    Updated: 2022/10/19 11:04:15 by laugarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
BNUS	= .bonus

HEADER	= libft.h
INCLUDE = -I ./

CFLAGS	= -Wall -Wextra -Werror
NORM	= norminette -R CheckForbiddenSourceHeader
RM		= rm -f
AR		= ar -rcs

SRC_FILES	= ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_atoi.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memset.c \
			  ft_strdup.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strncmp.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_putnbr_fd.c \
			  ft_calloc.c \
			  ft_memmove.c \
			  ft_strnstr.c \
			  ft_strjoin.c \
			  ft_substr.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_itoa.c \
			  ft_strtrim.c \
			  ft_split.c

BONUS_FILES	= ft_lstnew_bonus.c \
			  ft_lstadd_front_bonus.c \
			  ft_lstsize_bonus.c \
			  ft_lstlast_bonus.c \
			  ft_lstadd_back_bonus.c \
			  ft_lstdelone_bonus.c \
			  ft_lstclear_bonus.c \
			  ft_lstiter_bonus.c \
			  ft_lstmap_bonus.c

SRC_OBJ		= $(SRC_FILES:.c=.o)
BONUS_OBJ	= $(BONUS_FILES:.c=.o)


SRC_DEPS	= $(SRC_FILES:.c=.d)
BONUS_DEPS	= $(BONUS_FILES:.c=.d)

all: $(NAME)

%.o : %.c Makefile
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@
	@echo "Compilimg $<..."

$(NAME) : $(SRC_OBJ)
	@$(AR) $(NAME) $(SRC_OBJ)
	@echo Library compiled!

bonus: $(BNUS)

$(BNUS): $(SRC_OBJ) $(BONUS_OBJ)
	@$(AR) $(NAME) $(SRC_OBJ) $(BONUS_OBJ)
	@echo Library compiled!
	@touch $@

clean:
	@$(RM) $(SRC_OBJ) $(BONUS_OBJ) $(SRC_DEPS) $(BONUS_DEPS)

fclean: clean
	@$(RM) $(NAME) $(BNUS)

re: fclean all

norm:
	$(NORM)

-include $(SRC_DEPS)
-include $(BONUS_DEPS)

.PHONY: all clean fclean re norm bonus
