# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleonell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/10 09:28:04 by gleonell          #+#    #+#              #
#    Updated: 2020/09/10 09:28:04 by gleonell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

FLAGS = -Wall -Werror -Wextra -c

SRC = ft_printf.c \
ft_check_parameters.c \
ft_is_it_valid_string.c \
ft_read_format.c\
ft_start_set_flags.c \
ft_except_flags.c \
ft_get_precision.c \
ft_get_type.c \
ft_get_width.c \
ft_int_decimal.c \
ft_char.c \
ft_percent.c \
ft_pointer.c  \
ft_str.c \
ft_unsigned.c \
ft_hex_up.c \
ft_dec_to_hex.c \
ft_hex_itoa.c \
ft_atoi.c\
ft_utils_lib.c\
ft_str_out.c

OBJ = $(SRC:.c=.o)

CC = gcc

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -o $@ $<

clean:
	@ rm -f *.o

fclean: clean
	@ rm -f $(NAME)
	@ rm -f *.out

re: fclean all

.PHONY: all clean fclean re