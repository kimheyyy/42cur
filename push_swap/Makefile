# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:40:29 by hwankim           #+#    #+#              #
#    Updated: 2023/02/08 16:40:31 by hwankim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BNAME	= checker

CC		= cc
CFLAGS	= -Wall -Werror -Wextra 

LIBFT = libft.a

LIBFT_DIR = ./libft/
INC_DIR = ./includes/
INC_DIR_BONUS = ./checker_bonus/includes/

SRC_DIR		= 	./srcs/
SRC_FILES 	=					\
								$(SRC_DIR)setting_max_min.c \
								$(SRC_DIR)push_swap.c \
								$(SRC_DIR)main.c \
								$(SRC_DIR)free.c \
								


COMMAND_SRC_DIR = ./srcs/command_operations/
COMMAND_SRC_FILES =			\
								$(COMMAND_SRC_DIR)push.c \
								$(COMMAND_SRC_DIR)reverse_rotate.c \
								$(COMMAND_SRC_DIR)rotate.c \
								$(COMMAND_SRC_DIR)swap.c


STTINGS_SRC_DIR = ./srcs/settings/
STTINGS_SRC_FILES = 		\
								$(STTINGS_SRC_DIR)check_input.c \
								$(STTINGS_SRC_DIR)init_stack.c \
								$(STTINGS_SRC_DIR)ft_atoi.c

SORT_SRC_DIR = ./srcs/sort/
SORT_SRC_FILES = 			\
								$(SORT_SRC_DIR)control_under_three.c \
								$(SORT_SRC_DIR)sort_a_to_b.c \
								$(SORT_SRC_DIR)sort_b_to_a.c \
								$(SORT_SRC_DIR)sort_input_five.c \
								$(SORT_SRC_DIR)sort_input_three_a.c \
								$(SORT_SRC_DIR)sort_input_three_b.c \






SRC_OBJS				=		$(SRC_FILES:.c=.o)
COMMAND_SRC_OBJS		=		$(COMMAND_SRC_FILES:.c=.o)
STTINGS_SRC_OBJS		=		$(STTINGS_SRC_FILES:.c=.o)
SORT_SRC_OBJS			=		$(SORT_SRC_FILES:.c=.o)



SRC_DIR_BONUS		= ./checker_bonus/srcs/
SRC_FILES_BONUS 	=			\
								$(SRC_DIR_BONUS)checker.c \
								$(SRC_DIR_BONUS)do_operations.c \
								$(SRC_DIR_BONUS)free.c \
								$(SRC_DIR_BONUS)main.c 


COMMAND_SRC_DIR_BONUS = ./checker_bonus/srcs/command_operations/
COMMAND_SRC_FILES_BONUS =			\
								$(COMMAND_SRC_DIR_BONUS)push.c \
								$(COMMAND_SRC_DIR_BONUS)reverse_rotate.c \
								$(COMMAND_SRC_DIR_BONUS)rotate.c \
								$(COMMAND_SRC_DIR_BONUS)swap.c

GNL_SRC_DIR_BONUS		=	./checker_bonus/srcs/gnl/
GNL_SRC_FILES_BONUS		=	\
								$(GNL_SRC_DIR_BONUS)get_next_line_bonus.c \
								$(GNL_SRC_DIR_BONUS)get_next_line_utils_bonus.c

STTINGS_SRC_DIR_BONUS = ./checker_bonus/srcs/settings/
STTINGS_SRC_FILES_BONUS = 		\
								$(STTINGS_SRC_DIR_BONUS)check_input.c \
								$(STTINGS_SRC_DIR_BONUS)init_stack.c \
								$(STTINGS_SRC_DIR_BONUS)ft_atoi.c

SRC_OBJS_BONUS				=	$(SRC_FILES_BONUS:.c=.o)
COMMAND_SRC_OBJS_BONUS		=	$(COMMAND_SRC_FILES_BONUS:.c=.o)
GNL_SRC_OBJS_BONUS			=	$(GNL_SRC_FILES_BONUS:.c=.o)
STTINGS_SRC_OBJS_BONUS		=	$(STTINGS_SRC_FILES_BONUS:.c=.o)

AR		= ar -crs
RM		= rm -f

OBJECTS_BONUS	= $(SRC_OBJS_BONUS) $(COMMAND_SRC_OBJS_BONUS) $(GNL_SRC_OBJS_BONUS) $(STTINGS_SRC_OBJS_BONUS)
OBJECTS			= $(SRC_OBJS) $(COMMAND_SRC_OBJS) $(STTINGS_SRC_OBJS) $(SORT_SRC_OBJS)

all		:	$(NAME)

$(NAME)	:	$(OBJECTS)
			$(MAKE) -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

%.o 	: 	%.c
			$(CC) $(CFLAGS) -o $@ -I$(LIBFT_DIR) -c $^

bonus	:	$(BNAME)

$(BNAME) :	$(OBJECTS_BONUS)
			$(MAKE) -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

clean	:
			$(RM) $(OBJECTS_BONUS)
			$(RM) $(OBJECTS)

fclean	: 	clean
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(RM) $(NAME)
			$(RM) $(BNAME)
re		: 
			make fclean
			make all

.PHONY	: bonus all clean fclean re
