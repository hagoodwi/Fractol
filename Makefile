# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hagoodwi <hagoodwi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 15:27:54 by hagoodwi          #+#    #+#              #
#    Updated: 2020/11/10 19:37:29 by hagoodwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG	=	-g -Wall -Wextra -Werror -O3 -ffast-math
NAME	=	fractol
SRC_DIR	=	./src/
OBJ_DIR =	./obj/
INC_DIR	=	./inc/
HEAD	=	./inc/fractol.h

LIB_INC	=	-I /usr/local/include -I ./libft -I ./inc/
LIB_BIN	=	-L ./libft -lft -L /usr/local/lib -lmlx

FW		=	-framework OpenGL -framework AppKit

CFILES	=	main.c			\
			dop_func_2.c	\
			dop_func.c		\
			julia.c			\
			keys.c			\
			mandelbrot.c	\
			celtic.c		\
			burning_ship.c	\
			mandelbar.c

SRC		=	$(addprefix $(SRC_DIR), $(CFILES))

OFILES	=	$(patsubst %.c, %.o, $(CFILES))
OBJ		=	$(addprefix $(OBJ_DIR), $(OFILES))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	make -C ./libft
	gcc $(FLAG) $(LIB_INC) $(LIB_BIN) $(OBJ) -o $(NAME) $(FW)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEAD)
	gcc $(FLAG) $(LIB_INC) -o $@ -c $<;

clean:
	make clean -C ./libft
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
