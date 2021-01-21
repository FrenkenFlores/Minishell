# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wabomina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 03:39:54 by wabomina          #+#    #+#              #
#    Updated: 2021/01/21 03:39:56 by wabomina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

HEADER = libft.h

SRC = ft_arraylen.c\
      ft_atoi.c\
      ft_bzero.c\
      ft_calloc.c\
      ft_endwith.c\
      ft_isalnum.c\
      ft_isalpha.c\
      ft_isascii.c\
      ft_isdigit.c\
      ft_isprint.c\
      ft_isspace.c\
      ft_itoa.c\
      ft_itoa_base.c\
      ft_itoa_unsigned.c\
      ft_lstnew.c\
      ft_memccpy.c\
      ft_memchr.c\
      ft_memcmp.c\
      ft_memcpy.c\
      ft_memmove.c\
      ft_memset.c\
      ft_print_hex.c\
      ft_print_nbr.c\
      ft_print_pers.c\
      ft_printf.c\
      ft_putchar_fd.c\
      ft_putendl_fd.c\
      ft_putnbr_fd.c\
      ft_putstr_fd.c\
      ft_putstr_free.c\
      ft_putstrn.c\
      ft_split.c\
      ft_strchr.c\
      ft_strcmp.c\
      ft_strdup.c\
      ft_strisnum.c\
      ft_strjoin.c\
      ft_strlcat.c\
      ft_strlcpy.c\
      ft_strlen.c\
      ft_strmapi.c\
      ft_strncmp.c\
      ft_strnstr.c\
      ft_strrchr.c\
      ft_strtrim.c\
      ft_substr.c\
      ft_tolower.c\
      ft_toupper.c\
      get_next_line.c\
      get_next_line_utils.c\
      parse_params.c\
      utils.c

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): %.o: %.c
	$(CC) -c $(FLAGS) $< -I $(HEADER)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all