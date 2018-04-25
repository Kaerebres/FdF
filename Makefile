# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csimon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 10:26:16 by csimon            #+#    #+#              #
#    Updated: 2017/04/26 10:26:18 by csimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = main.c matrix.c display.c parse.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	cd libft && make
	cd minilibx_macos && make
	cc -o fdf $(SRC) libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit 

clean:
	$(MAKE) -C libft/ clean
	$(MAKE) -C minilibx_macos/ clean
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
