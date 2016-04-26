# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eplumeco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/07 16:48:05 by eplumeco          #+#    #+#              #
#    Updated: 2016/04/26 18:56:06 by eplumeco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = src
SRC_NAME = main.c mandelbrot.c draw.c check_errors.c julia.c glynn.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

PATH_INC = includes
PATH_LIBFT = libft/includes
LIBFT = libft/libft.a
PATH_MINILIBX = minilibx/
*/MINILIBX = -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit
MINILIBX = minilibx/libmlx.a  -framework OpenGL -framework AppKit

CC = clang
CFLAGS = -Wall -Wextra -Werror -g

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
INC = $(addprefix -I,$(PATH_INC) $(PATH_LIBFT) $(PATH_MINILIBX))

all: makelibft makeminilibx $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MINILIBX) $(OBJ) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

makelibft:
	make -C libft

makeminilibx:
	make -C minilibx

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -f $(NAME)

gfclean : fclean
	make fclean -C libft
	make clean -C minilibx

re: fclean all

norme:
	norminette $(SRC)
	norminette $(PATH_INC)/fractol.h

.PHONY: all lib clean fclean gfclean re norme makelibft makeminilibx
