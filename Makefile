# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fflores < fflores@student.21-school.ru>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 20:37:38 by wabomina          #+#    #+#              #
#    Updated: 2021/01/26 18:01:20 by fflores          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS
BLUE='\033[36m'
RESET='\033[0m'

HEADER = minishell.h
NAME = minishell
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = 	./source/parser/check_command.c\
		./source/parser/check_command_utils.c\
		./source/parser/check_tokens.c\
		./source/parser/execute.c\
		./source/parser/execute_utils.c\
		./source/parser/free_shell.c\
		./source/parser/expand_str.c\
		./source/parser/expand_str_utils.c\
		./source/parser/expand_variable.c\
		./source/parser/expand_utils.c\
		./source/parser/main.c\
		./source/parser/parse_line.c\
		./source/parser/parse_line_utils.c\
		./source/parser/parse_line_utils2.c\
		./source/parser/parse_tokens.c\
		./source/parser/parse_tokens_utils.c\
		./source/parser/prepath_check.c\
		./source/parser/print_error.c\
		./source/parser/readline.c\
		./source/parser/shell_gnl.c\
		./source/parser/signals.c\
		./source/parser/split_env_variable.c\
		./source/parser/utils_1.c\
		./source/parser/utils_2.c\
		./source/parser/utils_3.c\
		./source/builtins/echo.c\
		./source/builtins/env.c\
		./source/builtins/pwd.c\
		./source/builtins/exit.c\
		./source/builtins/cd.c\
		./source/builtins/export.c\
		./source/builtins/unset.c\
		./source/builtins/utils.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c
OBJS = ${SRCS:c=o}

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	@echo "\033[36m=====================================\033[0m"
	@echo "\033[36m=============MINISHELL===============\033[0m"
	@echo "\033[36m=====================================\033[0m"
	make -C libft
	make -C ft_printf
	$(CC) ./libft/libft.a ./ft_printf/libftprintf.a $(SRCS) -o $(NAME)

clean:
	make -C libft clean
	make -C ft_printf clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	make -C ft_printf fclean
	rm -f $(NAME)

re: fclean all	

norm:
	@echo "\033[36mMINISHELL SOURCES\033[0m"
	@norminette $(SRCS) $(HEADER)
