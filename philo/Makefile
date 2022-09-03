# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 09:28:01 by pmeising          #+#    #+#              #
#    Updated: 2022/09/03 16:13:02 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo

BONUS		:= philo_bonus

CC			:= gcc -g -pthread

CFLAGS		:= -Werror -Wextra -Wall -fsanitize=thread

RM			:= rm -f

HEADER		:= philosophers.h

DIR			:= ./

SRCS		:= $(DIR)main.c	\
			:= $(DIR)ft_error.c	\

OBJS		:= ${SRCS:.c=.o}

#___________________________###_______________________________________________________#
#	colours

C_GREEN		:= \033[0;92m
C_YELLOW	:= \033[0;93m
C_BLUE		:= \033[0;94m
C_STD		:= \033[0;39m
C_GREY		:= \033[2;30m
C_RED		:= \033[31m

.PHONY:		all clean fclean re

all:		${NAME}

%.o: %.c	
			@echo "$(C_GREY)~"
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			@echo "$(C_BLUE)Making o-files and compiling program.$(C_STD)"
			$(CC) $(OBJS) -o $(NAME)
			@echo "$(C_GREEN)<<.........................compilation complete................................>>$(C_STD)"

bonus:

re:			fclean all

clean:
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME) $(BONUS)

