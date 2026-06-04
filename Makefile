# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/01 21:01:11 by apinho-a          #+#    #+#              #
#    Updated: 2026/06/03 15:04:02 by apinho-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

FUNC = push_swap.c argv_parser.c stack_func.c

MACHINE_CODE = $(FUNC:.c=.o)

all : $(NAME) # first rule = default one

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(NAME) : $(MACHINE_CODE) $(LIBFT)
	$(CC) $(CFLAGS) $(MACHINE_CODE) $(LIBFT) -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
# creates the machine code .o ^
# $< = to depedency and $@ = to target

clean:
	rm -f $(MACHINE_CODE)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re