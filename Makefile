CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo
OBJ_DIR = obj

SRC_FILES = index.c utils.c free_memory.c init_philos.c philos_routine.c monitor.c
OBJECTS = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

OTHER_DIRS = -pthread

NO_COLOR = \033[0m
RED = \033[31m
GREEN = \033[32;5m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36;5m

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(OTHER_DIRS) -o $(NAME)
	@echo "$(GREEN)Object files created!$(NO_COLOR)"

clean:
	@echo "$(YELLOW)Cleaning...$(NO_COLOR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Full Cleaning...$(NO_COLOR)"
	@	rm -rf $(OBJ_DIR) $(NAME)

re: fclean all

.PHONY: all clean fclean re