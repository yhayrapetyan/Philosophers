SRC =			init_data.c \
				monitoring.c \
				philo_bonus.c \
				routine.c \
				clean_data.c \
				should_stop.c \
				getters.c \
				setters.c

HELPERS_SRC = 	ft_atoi.c \
				ft_error.c \
				ft_itoa.c \
				ft_strjoin.c \
				ft_strlen.c \
				ft_usleep.c \
				print_instructions.c \
				print_message.c

VALIDATION_SRC = 	check_input.c

HEADERS = 	philo_bonus_utils.h \
			philo_bonus.h

SRC_DIR = ./src/main/
HELPERS_DIR = ./src/helpers/
VALIDATION_DIR = ./src/validation/
INC = ./includes/

HEADERS := $(addprefix $(INC), $(HEADERS))
SRC := $(addprefix $(SRC_DIR), $(SRC))
VALIDATION_SRC := $(addprefix $(VALIDATION_DIR), $(VALIDATION_SRC))
HELPERS_SRC := $(addprefix $(HELPERS_DIR), $(HELPERS_SRC))
OBJS = $(SRC:.c=.o)

SRC += $(VALIDATION_SRC)
SRC += $(HELPERS_SRC)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus
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

sanitize: fclean print_info $(OBJS)
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

.PHONY: all clean fclean re sanitize print_name print_info
