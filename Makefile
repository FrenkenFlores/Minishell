# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabomina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 03:46:23 by wabomina          #+#    #+#              #
#    Updated: 2021/01/21 03:46:25 by wabomina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = -Wall -Wextra -Werror
CC = gcc

HEADER = minishell.h

SRCS = 	./parser/check_command.c\
		./parser/check_command_utils.c\
		./parser/check_tokens.c\
		./parser/execute.c\
		./parser/execute_utils.c\
		./parser/exit_shell.c\
		./parser/expand_str.c\
		./parser/expand_str_utils.c\
		./parser/expand_variable.c\
		./parser/main.c\
		./parser/parse_line.c\
		./parser/parse_line_utils.c\
		./parser/parse_line_utils2.c\
		./parser/parse_tokens.c\
		./parser/parse_tokens_utils.c\
		./parser/print_error.c\
		./parser/readline.c\
		./parser/free_buf.c\
		./parser/signals.c\
		./parser/split_env_variable.c\
		./parser/standart_functions_utils.c\
		./parser/utils_1.c\
		./parser/utils_2.c\
		./parser/utils_3.c\
		./builtins/cd.c\
		./builtins/echo.c\
		./builtins/env.c\
		./builtins/exit.c\
		./builtins/export.c\
		./builtins/pwd.c\
		./builtins/unset.c

SRC_DIR = ./srcs/
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

OBJ = $(SRC:.c=.o)

OBJ_DIR = ./objs/
OBJ_FILES = $(addprefix $(OBJ_DIR), $(OBJ))

LIBFT = ./libft/libft.a
LIB_DIR = ./libft/
LIB_HDR = ./libft/libft.h

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(FLAGS) -I$(LIB_HDR) -I$(HEADER) -o $@ -c $<

$(LIBFT):
	@make -C $(LIB_DIR)
	@echo "LIBFT compiled"

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME) $(LIBFT)

clean:
	make clean -C libft/
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean $(NAME)
