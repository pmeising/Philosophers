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
			@echo "$(GREY)From the subject pdf: The program should take the following arguments:\n * Number_of_philosophers: The number of philosophers and also the number of forks.\n * Time_to_die (in ms): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.\n * Time_to_eat (in ms): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.\n * Time_to_sleep (in ms): The time a philosopher will spend sleeping.\n * Number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.\n * Each philosopher has a number ranging from 1 to number_of_philosophers.\n * Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.$(END_COLOR)"
			@echo "\n$(BLUE)Syntax: $(END_COLOR) ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep number_of_times_each_philosopher_must_eat \n\n$(GREEN)Example: $(END_COLOR)./philo 5 500 200 200 2\n"
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