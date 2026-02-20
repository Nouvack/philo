# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 11:25:55 by nsantand          #+#    #+#              #
#    Updated: 2025/01/18 18:29:11 by nsantand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED       = \033[1;31m
GREEN     = \033[1;32m
BLUE      = \033[1;34m
CYAN      = \033[1;36m
DEF_COLOR = \033[0;39m

NAME    := philo
CC      := cc 
CFLAGS  :=  -Wall -Wextra -Werror -fsanitize=thread -g3
SRC_DIR := src/
SRC := $(SRC_DIR)main.c $(SRC_DIR)/tools/tools_str.c $(SRC_DIR)/tools/tools_placeholder.c $(SRC_DIR)/tools/tools_split.c  $(SRC_DIR)/tools/tools_parse.c $(SRC_DIR)/tools/tools_check.c
OBJ     := $(SRC:.c=.o) 
HEADERS := -I .


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJ) -o $(NAME)
	@echo "$(CYAN)Philosophers Compiled$(DEF_COLOR)🇵🇪"

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo "$(RED)All object files erased!$(DEF_COLOR)🇵🇪"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

valgrind: re
	valgrind -s \
		./$(NAME)

.PHONY: all libft clean fclean re valgrind