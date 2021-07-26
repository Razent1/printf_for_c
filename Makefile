# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilya <ilya@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 03:24:34 by ilya              #+#    #+#              #
#    Updated: 2021/01/19 15:42:45 by ilya             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
				ft_int_type.c ft_parser.c ft_pointer_type.c ft_processor.c\
				ft_string_type.c ft_un_int_type.c\
				ft_x_type.c parse_numbers.c utils_for_int.c ft_char_type.c\
				ft_prec_type.c ft_un_itoa.c utils_for_x.c

LIB_PATH = libft/
LIB_SRC = ft_bzero.c  \
			ft_strlen.c  ft_strchr.c \
			ft_isdigit.c ft_itoa.c ft_putchar.c ft_strdup.c\

OBJ += $(SRC:.c=.o)
OBJ += $(addprefix $(LIB_PATH),$(LIB_SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re