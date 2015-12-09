# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tauvray <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/17 11:01:12 by tauvray           #+#    #+#              #
#*   Updated: 2014/11/21 15:01:43 by tauvray          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

# *********************************VARIABLES***********************************#

NAME = ft_select

SRC_DIR = srcs/

SRC	 = main.c \
	   init.c \
	   utilitaire.c \
	   utilitaire2.c \
	   utilitaire3.c \
	   ft_select.c \
	   ft_move.c \
	   ft_move2.c \
	   ft_move_vert.c \
	   bonus.c \
	   bonus2.c \
	   bonus3.c

OBJ = $(SRC:.c=.o)

INC = includes/

LIBINC = libft/includes/

LIB = libft.a

BIN_DIR = bin/

CC = clang

OPTS = -Wall -Werror -Wextra -g

# *********************************RULES***************************************#

all			: $(NAME)


$(NAME)		: $(OBJ)
	make -C libft/
	$(CC) $(OPTS) -I $(LIBINC) -Llibft -lft -I includes/ $(OBJ) -o $(NAME) -ltermcap

clean 		:
	rm -f $(OBJ)

fclean		: clean
	make -C libft/ fclean
	rm -f $(NAME)

re			: fclean all
	make -C libft/ re

%.o			:	$(SRC_DIR)%.c
	$(CC) $(OPTS) -c -I $(INC) -I $(LIBINC) $< -o $@

.PHONY		: all clean fclean re
