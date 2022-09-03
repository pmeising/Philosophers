# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmeising <pmeising@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 09:28:01 by pmeising          #+#    #+#              #
#    Updated: 2022/09/01 11:14:09 by pmeising         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo

CC		:= gcc -g

CFLAGS	:= -Wall -Werror -Wall -pthread -fsanitize=thread

RM		:= rm -f

HEADER	:= philosophers.h

DIR		:= ./philo/

SRCS	:= $(DIR)main.c 		\
		:= $(DIR)ft_error.c 	\
		# := $(DIR)

OBJS		:= ${SRCS:.c=.o}

# B_OBJS		:= ${B_SRCS:.c=.o}

#____________________________________###_______________________________________#

C_GREEN		:= \033[0;92m
C_YELLOW	:= \033[0;93m
C_BLUE		:= \033[0;94m
C_STD		:= \033[0;39m
C_GREY		:= \033[2;30m
C_RED		:= \033[31m


#____________________________________###_______________________________________#


.PHONY:		all clean fclean re

all:		${OBJS} ${NAME}

%.o: %.c	$(SRCS)
			@echo "$(C_GREY)~"
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
			@echo "$(C_BLUE)Making o-files and compiling program.$(C_STD)"
			$(CC) $(OBJS) -o $(NAME)
			@echo "$(C_GREEN)<<.........................compilation complete................................>>$(C_STD)"

re:			fclean all

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

