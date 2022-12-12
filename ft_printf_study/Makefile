# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hwankim <hwankim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 22:53:58 by hwankim           #+#    #+#              #
#    Updated: 2022/11/29 23:43:06 by hwankim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	utils.c ft_c_print.c ft_s_print.c ft_p_print.c ft_di_print.c ft_u_print.c ft_xx_print.c ft_printf.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	 libftprintf.a

$(NAME) 	:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all			:	$(NAME)

%.o			:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re