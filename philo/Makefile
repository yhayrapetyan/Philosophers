SRC =			philo.c \
				monitoring.c \
				routine.c \
				clean_data.c \
				eat.c \
				think.c \
				fork_utils.c \
				philo_sleep.c \
				philo_died.c \
				init_data.c


HELPERS_SRC = 	print_instructions.c \
				ft_error.c \
				ft_strlen.c \
				print_message.c \
				ft_atoi.c \
				ft_usleep.c \

GETTERS_SRC = 	get_time.c \
				can_print.c \
                get_die_time.c \
                get_eat_time.c \
                get_last_eat_time.c \
                get_nb_philos.c \
                get_philo_state.c \
                get_sleep_time.c \
                get_start_time.c \
                can_iterate.c \
                get_nb_meals.c

SETTERS_SRC = 	set_philo_state.c \
				update_last_meal_time.c \
				update_number_meals_had.c


VALIDATION_SRC = 	check_input.c

HEADERS = 	philo_utils.h \
			philo.h

SRC_DIR = ./src/main/
HELPERS_DIR = ./src/helpers/
VALIDATION_DIR = ./src/validation/
GETTERS_DIR = ./src/main/getters/
SETTERS_DIR = ./src/main/setters/
INC = ./includes/

HEADERS := $(addprefix $(INC), $(HEADERS))
SRC := $(addprefix $(SRC_DIR), $(SRC))
GETTERS_SRC := $(addprefix $(GETTERS_DIR), $(GETTERS_SRC))
SETTERS_SRC := $(addprefix $(SETTERS_DIR), $(SETTERS_SRC))
VALIDATION_SRC := $(addprefix $(VALIDATION_DIR), $(VALIDATION_SRC))
HELPERS_SRC := $(addprefix $(HELPERS_DIR), $(HELPERS_SRC))
OBJS = $(SRC:.c=.o)

SRC += $(VALIDATION_SRC)
SRC += $(HELPERS_SRC)
SRC += $(GETTERS_SRC)
SRC += $(SETTERS_SRC)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
RM = rm -f

BLUE   = \033[0;34m
GREEN    = \033[0;32m
RED = \033[0;31m
YELLOW  = \033[0;33m
NO_COLOR    = \033[m


SRC := $(shell printf "$(SRC)" | tr '\r' '\n')
SRC_COUNT_TOT := $(words $(SRC))
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

all: print_info $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "%b" "$(BLUE)\n$@ $(GREEN)[✓]\n"

$(OBJS): $(HEADERS) Makefile

sanitize: $(OBJS)
	@cc $(OBJS) -fsanitize=thread -o $(NAME)

.c.o:
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@printf "\r%18s\r$(YELLOW)[ %d/%d (%d%%) ]$(NO_COLOR)" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -I $(INC) -c  $< -o $(<:.c=.o)

clean: print_name
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@printf "%b" "$(BLUE)$@: $(GREEN)[✓]\n"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@printf "%b" "$(BLUE)$@: $(GREEN)[✓]\n"

re: fclean all
	@printf "%b" "$(BLUE)$@: $(GREEN)[✓]\n"

print_info: print_name
	@printf "%b" "$(BLUE)Compiler: $(GREEN)$(CC)\n"
	@printf "%b" "$(BLUE)Name: $(GREEN)$(NAME)\n"
	@printf "%b" "$(BLUE)C Flags: $(GREEN)$(CFLAGS)\n"
	@printf "%b" "$(BLUE)Src Count: $(GREEN)$(SRC_COUNT_TOT)$(NO_COLOR)\n"


print_name:
	@printf "%b" "$(BLUE)"
	@echo "Philosophers\n"

.PHONY: all clean fclean re sanitize bonus print_name print_info
