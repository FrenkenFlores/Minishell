HEADER = minishell.h
NAME = minishell
FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = 	./source/parser/check_command.c\
		./source/parser/check_command_utils.c\
		./source/parser/check_tokens.c\
		./source/parser/execute.c\
		./source/parser/execute_utils.c\
		./source/parser/exit_shell.c\
		./source/parser/expand_str.c\
		./source/parser/expand_str_utils.c\
		./source/parser/expand_variable.c\
		./source/parser/main.c\
		./source/parser/parse_line.c\
		./source/parser/parse_line_utils.c\
		./source/parser/parse_line_utils2.c\
		./source/parser/parse_tokens.c\
		./source/parser/parse_tokens_utils.c\
		./source/parser/print_error.c\
		./source/parser/readline.c\
		./source/parser/free_buf.c\
		./source/parser/signals.c\
		./source/parser/split_env_variable.c\
		./source/parser/standart_functions_utils.c\
		./source/parser/utils_1.c\
		./source/parser/utils_2.c\
		./source/parser/utils_3.c\
		./source/builtins/echo.c\
		./source/builtins/env.c\
		./source/builtins/pwd.c
OBJS = ${SRCS:c=o}

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLAGS) ./libft/libft.a $(SRCS) -o $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all	
