# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/01 21:01:11 by apinho-a          #+#    #+#              #
#    Updated: 2026/06/11 18:13:13 by apinho-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_DIR)$(LIBFT_NAME)

PRINTF_DIR = ft_printf/

PRINTF_NAME = libftprintf.a

PRINTF = $(PRINTF_DIR)$(PRINTF_NAME)

FUNC = main.c argv_parser.c argv_parser_utils.c stack_func.c flag_parser.c disorder_strat.c output_printing.c

MACHINE_CODE = $(FUNC:.c=.o)

all : $(NAME) # first rule = default one

$(LIBFT) :
	make -C $(LIBFT_DIR)

$(PRINTF) :
	make -C $(PRINTF_DIR)

$(NAME) : $(MACHINE_CODE) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(MACHINE_CODE) $(LIBFT) $(PRINTF) -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
# creates the machine code .o ^
# $< = to depedency and $@ = to target

clean:
	rm -f $(MACHINE_CODE)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) fclean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re