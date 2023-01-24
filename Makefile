# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gjupy <gjupy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 15:39:40 by gjupy             #+#    #+#              #
#    Updated: 2022/08/22 13:19:27 by gjupy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  = so_long
CC    = gcc
FLAGS = -Wall -Werror -Wextra
MLX   = ./srcs/MLX42/libmlx42.a
GLFW  = ./srcs/MLX42/lib-x86_64/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit
LIBFT = ./libs/libft/libft.a
SRCS  = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
		./srcs/checker_utils.c ./srcs/checkers.c ./srcs/game_init.c ./srcs/read_map.c \
		./srcs/key_hooks.c ./srcs/key_hooks_utils.c ./srcs/exit_and_free_game.c \
		main.c

OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C libs/libft
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(GLFW) -o $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

inside: $(OBJS) $(LIBFT) so_long.h
	ar -t $(NAME)

git:
	git add .
	git commit -m "commit"
	git push

.PHONY: all clean fclean re git libft