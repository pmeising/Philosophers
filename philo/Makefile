# **************************************************************************** #
# VARIABLES

NAME				:= philo

CC					:= gcc
CFLAGS				:= -Wall -Wextra -Werror -pthread
DEBUG				:= none
ifeq ($(DEBUG), ON)
	CFLAGS			:= -Wall -Wextra -Werror -pthread -fsanitize=thread -g
endif

RM					:= rm -rf
INCS				:= -I ./inc/
HEADER				:= ./inc/philosophers.h

SRC_DIR				:= ./srcs/
OBJ_DIR				:= ./objs/

# **************************************************************************** #
# COLORS

GREEN				:= \033[0;92m
YELLOW				:= \033[0;93m
BLUE				:= \033[0;94m
GREY				:= \033[2;30m
END_COLOR			:= \033[0;39m

# **************************************************************************** #
# SOURCES

SRC_FILES			:=	ft_atoi_phil.c ft_eat_sleep_think.c ft_error.c ft_input_check.c \
						ft_lone_thinker.c ft_routine.c ft_utils.c ft_waiter_routine.c main.c \

OBJ_FILES			:= ${SRC_FILES:.c=.o}

SRC					:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ					:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# **************************************************************************** #
# RULES

# all :	$(OBJ_DIR) $(NAME)
all : $(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@echo "\n$(GREEN)Program '$(NAME)' compiled successfully.\n$(END_COLOR)"
# -C	:	make option that tells make to change directory before execution.


$(OBJ_DIR)%.o : $(SRC_DIR)%.c
				$(CC) $(CFLAGS)  -c $< -o $@ $(INCS)
# -c	:	gcc option to compile each .c file into .o file.
# $<	:	represents the first prerequisite of the rule (each .c file 
#			contained in the src folder).
# -o	:	gcc option to define the name of the program (output) file :
#			"push_swap".
# $@	:	represents the filename of the target of the rule, i.e. each output
#			file which will be linked with the so_long.h header file.

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

debug:  $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS_SANITIZE) $(OBJ) -o $(NAME)
	@echo "$(YELLOW)/!\ $(NAME) compiled with -fsanitize=thread -g flag!$(END_COLOR)"
# -C	:	make option that tells make to change directory before execution.

clean: 
	$(RM) $(OBJ)

fclean: clean
	@echo "$(BLUE)Cleaning up...$(END_COLOR)"
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Clean up successfull.$(END_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned all and rebuilt program '$(NAME)'!$(END_COLOR)"

.PHONY:		all clean fclean re