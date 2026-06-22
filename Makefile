# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/01 21:01:11 by apinho-a          #+#    #+#              #
#    Updated: 2026/06/22 17:10:45 by apinho-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -Iincludes/

LIBFT_DIR = libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

FUNC =	argument_parsing/argv_parser.c argument_parsing/argv_parser_utils.c \
		argument_parsing/flag_parser.c argument_parsing/disorder_strat.c \
		argument_parsing/insertion_sort.c \
		stack_functions/stack_func.c \
 		output_printing/output_printing.c \
		algorithms/algorithm_routing.c algorithms/medium_algorithm.c \
		algorithms/medium_algorithm_utils.c \
		operations/push_op.c operations/revrot_op.c operations/rotate_op.c \
		operations/swap_op.c \
		main.c

MACHINE_CODE = $(FUNC:.c=.o)

all : $(NAME) # first rule = default one

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(PRINTF) :
	make -C $(PRINTF_DIR)

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
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re