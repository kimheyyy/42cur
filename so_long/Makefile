# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 13:40:37 by hwankim           #+#    #+#              #
#    Updated: 2023/01/30 13:40:39 by hwankim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g
MFLAGS 	= -lmlx -framework OpenGl -framework AppKit -Imlx
MLX_DIR = mlx

SRC_DIR		= 	./src/
SRC_FILES 	=					\
								$(SRC_DIR)so_long.c \
								$(SRC_DIR)draw_map.c \
								$(SRC_DIR)utils.c \
								$(SRC_DIR)utils2.c \
								$(SRC_DIR)exit_game.c \
								$(SRC_DIR)get_next_line.c \
								$(SRC_DIR)get_next_line_utils.c \
								$(SRC_DIR)move.c \
								$(SRC_DIR)dfs.c \
								$(SRC_DIR)key_to_map.c \
								$(SRC_DIR)key_to_map2.c \
								$(SRC_DIR)map_parsing.c \
								$(SRC_DIR)print_error.c \
								$(SRC_DIR)set_param.c \



SRC_OBJS				=		$(SRC_FILES:.c=.o)

AR		= ar -crs
RM		= rm -f

OBJECTS			= $(SRC_OBJS)

all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			$(MAKE) -C mlx
			$(CC) $(CFLAGS) -L./$(MLX_DIR) $(MFLAGS) $(OBJECTS) -o $(NAME)


clean	:
			$(RM) $(OBJECTS)

fclean	: 	clean
			$(RM) $(NAME)
re		:
			make fclean
			make all

.PHONY	:  all clean fclean re